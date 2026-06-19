#include "semantico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
int semantic_errors = 0;

void sem_error(const char* msg) {
    fprintf(stderr, "ERRO SEMANTICO na linha %d: %s\n", yylineno, msg);
    semantic_errors++;
}

int semantic(Node* root) {
    Tabelas* tab = newTabelas();
    Tabela* global_tab = newTabela();
    push(tab, global_tab);
    
    dfs(root, tab, TipoINT_Node); // Dummy current_func_type
    
    // Check if principal exists
    Simbolo* princ = find_local(global_tab, "principal");
    if (!princ || princ->cat != CAT_FUNC) {
        fprintf(stderr, "ERRO SEMANTICO: Funcao 'principal' nao encontrada.\n");
        semantic_errors++;
    }
    
    pop(tab);
    free(tab);
    
    return semantic_errors;
}

Prod semantic_Expr(Node* u, Tabelas* tab);

void dfs_ListVar(Node* u, Tabelas* tab, Prod tipo, int is_global) {
    if(!u) return;
    if(u->tipo == ListVar_Node) {
        Node* curr = u->f[0];
        if(curr->tipo == Identificador_Node) {
            addVar(tab->last->tab, curr->lexema, tipo, is_global);
        } else if(curr->tipo == DeclVetor_Node) {
            int tamanho = atoi(curr->f[1]->lexema);
            addVetor(tab->last->tab, curr->f[0]->lexema, tipo, tamanho, is_global);
        }
        dfs_ListVar(u->f[1], tab, tipo, is_global);
    }
}

void dfs_ListaDeclVar(Node* u, Tabelas* tab, int is_global) {
    if(!u) return;
    if(u->tipo == LstDeclVar_Node) {
        Prod tipo = u->f[1]->tipo; // TipoINT_Node or TipoCAR_Node
        dfs_ListVar(u->f[0], tab, tipo, is_global);
        dfs_ListaDeclVar(u->f[2], tab, is_global);
    }
}

void dfs_VarSection(Node* u, Tabelas* tab, int is_global) {
    if(!u) return;
    if(u->tipo == VarSection_Node) {
        dfs_ListaDeclVar(u->f[0], tab, is_global);
    }
}

ParamInfo* dfs_ListaParametros(Node* u, Tabelas* tab, int num_params, int* out_count) {
    if(!u) { *out_count = 0; return NULL; }
    if(u->tipo == LstParam_Node) {
        ParamInfo* pinfo = (ParamInfo*) malloc(sizeof(ParamInfo));
        Node* param = u->f[0]; // Param_Node ou ParamVetor_Node
        pinfo->tipo = param->f[1]->tipo;
        if(param->tipo == Param_Node) pinfo->cat = CAT_PARAM;
        else pinfo->cat = CAT_PARAM_VETOR;
        
        pinfo->prox = dfs_ListaParametros(u->f[1], tab, num_params + 1, out_count);
        (*out_count)++;
        return pinfo;
    }
    return NULL;
}

void process_params(Node* u, Tabelas* tab) {
    if(!u) return;
    if(u->tipo == LstParam_Node) {
        Node* param = u->f[0];
        Prod tipo = param->f[1]->tipo;
        if(param->tipo == Param_Node) {
            addParam(tab->last->tab, param->f[0]->lexema, tipo, 0, CAT_PARAM);
        } else {
            addParam(tab->last->tab, param->f[0]->lexema, tipo, 0, CAT_PARAM_VETOR);
        }
        process_params(u->f[1], tab);
    }
}

void dfs_DeclFunc(Node* u, Tabelas* tab) {
    if(!u) return;
    if(u->tipo == LstFunc_Node) {
        Node* func = u->f[0];
        char* nome = func->f[0]->lexema;
        int param_count = 0;
        ParamInfo* pinfo = dfs_ListaParametros(func->f[1], tab, 0, &param_count);
        Prod ret_tipo = func->f[2]->tipo;
        
        addFunc(tab->last->tab, nome, ret_tipo, param_count, pinfo);
        
        // Entra no escopo da funcao
        Tabela* func_tab = newTabela();
        push(tab, func_tab);
        
        // Adiciona parametros no escopo da funcao
        process_params(func->f[1], tab);
        
        // Processa o bloco da funcao
        dfs(func->f[3], tab, ret_tipo);
        
        pop(tab);
        
        dfs_DeclFunc(u->f[1], tab);
    }
}

Prod semantic_Expr(Node* u, Tabelas* tab) {
    if(!u) return Programa_Node;
    yylineno = u->linha;
    
    if(u->tipo == IntConst_Node) return TipoINT_Node;
    if(u->tipo == CarConst_Node) return TipoCAR_Node;
    if(u->tipo == Identificador_Node) {
        Simbolo* s = find(tab, u->lexema);
        if(!s) { sem_error("Variavel nao declarada"); return TipoINT_Node; }
        if(s->cat == CAT_FUNC) sem_error("Uso incorreto de funcao");
        return s->tipo;
    }
    if(u->tipo == AcessoVetor_Node) {
        Simbolo* s = find(tab, u->f[0]->lexema);
        if(!s) { sem_error("Vetor nao declarado"); return TipoINT_Node; }
        if(s->cat != CAT_VETOR && s->cat != CAT_PARAM_VETOR) sem_error("Acesso de vetor em variavel simples");
        Prod idx = semantic_Expr(u->f[1], tab);
        if(idx != TipoINT_Node) sem_error("Indice de vetor deve ser int");
        return s->tipo;
    }
    if(u->tipo == Call_Node || u->tipo == CallEmpty_Node) {
        Simbolo* s = find(tab, u->f[0]->lexema);
        if(!s || s->cat != CAT_FUNC) { sem_error("Funcao nao declarada ou uso incorreto"); return TipoINT_Node; }
        
        ParamInfo* expected = s->params;
        void check_args(Node* args) {
            if(!args) return;
            if(args->tipo == LstExpr_Node) {
                if(args->f[1]) {
                    check_args(args->f[0]);
                    check_args(args->f[1]); // Wait, the right child of LstExpr_Node is NOT LstExpr_Node, it is Expr!
                } else {
                    check_args(args->f[0]); // It's just Expr
                }
                return;
            }
            
            // args is Expr
            if(!expected) { sem_error("Muitos argumentos na chamada de funcao"); return; }
            Node* expr = args;
            Prod tipo_arg = semantic_Expr(expr, tab);
            
            // Se for passagem de vetor
            if(expected->cat == CAT_PARAM_VETOR) {
                if(expr->tipo != Identificador_Node) {
                    sem_error("Argumento deve ser um vetor");
                } else {
                    Simbolo* sv = find(tab, expr->lexema);
                    if(!sv || (sv->cat != CAT_VETOR && sv->cat != CAT_PARAM_VETOR)) {
                        sem_error("Argumento deve ser um vetor");
                    } else if(sv->tipo != expected->tipo) {
                        sem_error("Vetor de tipo diferente do parametro");
                    }
                }
            } else {
                if(tipo_arg != expected->tipo) sem_error("Tipo de argumento incompativel");
                if(expr->tipo == Identificador_Node) {
                    Simbolo* sa = find(tab, expr->lexema);
                    if(sa && (sa->cat == CAT_VETOR || sa->cat == CAT_PARAM_VETOR)) {
                        sem_error("Passando vetor como variavel simples");
                    }
                }
            }
            expected = expected->prox;
        }
        
        if(u->tipo == Call_Node) check_args(u->f[1]);
        if(expected) sem_error("Poucos argumentos na chamada de funcao");
        return s->tipo;
    }
    
    // Operacoes
    if(u->tipo == Expr_Minus_Node || u->tipo == Expr_Neg_Node) {
        Prod t = semantic_Expr(u->f[0], tab);
        return TipoINT_Node; // operacoes logicas ou aritmeticas unarias sempre no int ou int
    }
    
    if(u->tipo == Expr_Ou_Node || u->tipo == Expr_E_Node || 
       u->tipo == Expr_Igual_Node || u->tipo == Expr_Dif_Node || 
       u->tipo == Expr_Menor_Node || u->tipo == Expr_Maior_Node || 
       u->tipo == Expr_MenorIgual_Node || u->tipo == Expr_MaiorIgual_Node ||
       u->tipo == Expr_Add_Node || u->tipo == Expr_Sub_Node || 
       u->tipo == Expr_Mul_Node || u->tipo == Expr_Div_Node) {
           
        Prod t1 = semantic_Expr(u->f[0], tab);
        Prod t2 = semantic_Expr(u->f[1], tab);
        if(t1 != t2) sem_error("Tipos incompativeis na expressao");
        
        if(u->tipo >= Expr_Add_Node && u->tipo <= Expr_Div_Node) {
            if(t1 != TipoINT_Node) sem_error("Aritmetica permitida apenas para INT");
        }
        return TipoINT_Node;
    }
    
    if(u->tipo == Expr_Atr_Node) {
        Prod t1 = semantic_Expr(u->f[0], tab);
        Prod t2 = semantic_Expr(u->f[1], tab);
        if(t1 != t2) sem_error("Tipos incompativeis na atribuicao");
        
        // Verifica se f[0] é vetor inteiro sem indice (atribuicao de vetor pra vetor)
        if(u->f[0]->tipo == Identificador_Node) {
            Simbolo* s = find(tab, u->f[0]->lexema);
            if(s && (s->cat == CAT_VETOR || s->cat == CAT_PARAM_VETOR)) {
                if(u->f[1]->tipo != Identificador_Node) {
                    sem_error("Atribuicao de expressao para vetor");
                } else {
                    Simbolo* s2 = find(tab, u->f[1]->lexema);
                    if(!s2 || (s2->cat != CAT_VETOR && s2->cat != CAT_PARAM_VETOR)) {
                        sem_error("Atribuicao de não vetor para vetor");
                    }
                }
            }
        }
        return t2;
    }
    
    return TipoINT_Node;
}

void dfs(Node* u, Tabelas* tab, Prod current_func_type) {
    if(!u) return;
    yylineno = u->linha;
    
    if(u->tipo == Programa_Node) {
        dfs(u->f[0], tab, current_func_type); // Globais
        dfs_DeclFunc(u->f[1], tab); // Funcoes
        dfs(u->f[2], tab, TipoINT_Node); // Principal
    } else if(u->tipo == DeclVarGlobais_Node) {
        dfs_VarSection(u->f[0], tab, 1);
    } else if(u->tipo == Bloco_Node) {
        dfs(u->f[0], tab, current_func_type);
    } else if(u->tipo == BlocoVar_Node) {
        Tabela* local_tab = newTabela();
        push(tab, local_tab);
        dfs_VarSection(u->f[0], tab, 0);
        dfs(u->f[1], tab, current_func_type);
        pop(tab);
    } else if(u->tipo == LstCmd_Node) {
        dfs(u->f[0], tab, current_func_type);
        dfs(u->f[1], tab, current_func_type);
    } else if(u->tipo == Expr_Node) {
        semantic_Expr(u->f[0], tab);
    } else if(u->tipo == Retorne_Node) {
        Prod t = semantic_Expr(u->f[0], tab);
        if(t != current_func_type) sem_error("Tipo de retorno incompativel");
    } else if(u->tipo == Leia_Node) {
        semantic_Expr(u->f[0], tab);
    } else if(u->tipo == Escreva_Node) {
        semantic_Expr(u->f[0], tab);
    } else if(u->tipo == Se_Node) {
        Prod t = semantic_Expr(u->f[0], tab);
        // int ou car serve? Nao, booleano e' avaliado
        dfs(u->f[1], tab, current_func_type);
    } else if(u->tipo == Se_Senao_Node) {
        Prod t = semantic_Expr(u->f[0], tab);
        dfs(u->f[1], tab, current_func_type);
        dfs(u->f[2], tab, current_func_type);
    } else if(u->tipo == Enquanto_Node) {
        Prod t = semantic_Expr(u->f[0], tab);
        dfs(u->f[1], tab, current_func_type);
    } else if(u->tipo == DeclPrograma_Node) {
        // Principal é como uma funcao int principal()
        addFunc(tab->last->tab, "principal", TipoINT_Node, 0, NULL);
        Tabela* func_tab = newTabela();
        push(tab, func_tab);
        dfs(u->f[0], tab, TipoINT_Node);
        pop(tab);
    }
}
