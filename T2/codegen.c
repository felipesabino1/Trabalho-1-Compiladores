#include "codegen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
int label_count = 0;
int loop_label_count = 0;
char current_func_name[256] = "";

int new_label() { return ++label_count; }

void cgen_Expr(Node* u, Tabelas* tab);
void cgen_Cmd(Node* u, Tabelas* tab);
void cgen_Bloco(Node* u, Tabelas* tab);
void cgen_Func(Node* u, Tabelas* tab);

// Offset management for code gen
void addVar_cg(Tabela* t, char* var, Prod tipo, int is_global) {
    Simbolo* s = (Simbolo*) malloc(sizeof(Simbolo));
    strcpy(s->nome, var);
    s->tipo = tipo;
    s->cat = CAT_VAR;
    if(is_global) {
        // Alocar global
        printf("\t.data\n");
        printf("global_%s:\t.word 0\n", var);
        printf("\t.text\n");
    } else {
        t->offset_atual -= 4;
        s->endereco = t->offset_atual;
        // printf("\t# Local %s em %d($fp)\n", var, s->endereco);
    }
    // inserir na tabela
    int h = hash(s->nome);
    s->prox = t->tab[h];
    t->tab[h] = s;
}

void addVetor_cg(Tabela* t, char* var, Prod tipo, int tamanho, int is_global) {
    Simbolo* s = (Simbolo*) malloc(sizeof(Simbolo));
    strcpy(s->nome, var);
    s->tipo = tipo;
    s->cat = CAT_VETOR;
    s->tamanho = tamanho;
    if(is_global) {
        printf("\t.data\n");
        printf("global_%s:\t.space %d\n", var, 4 * tamanho);
        printf("\t.text\n");
    } else {
        t->offset_atual -= (4 * tamanho);
        s->endereco = t->offset_atual; // Endereco base
    }
    int h = hash(s->nome);
    s->prox = t->tab[h];
    t->tab[h] = s;
}

void cg_ListVar(Node* u, Tabelas* tab, Prod tipo, int is_global) {
    if(!u) return;
    if(u->tipo == ListVar_Node) {
        Node* curr = u->f[0];
        if(curr->tipo == Identificador_Node) {
            addVar_cg(tab->last->tab, curr->lexema, tipo, is_global);
            if(!is_global) printf("\taddiu $sp, $sp, -4\n");
        } else if(curr->tipo == DeclVetor_Node) {
            int tamanho = atoi(curr->f[1]->lexema);
            addVetor_cg(tab->last->tab, curr->f[0]->lexema, tipo, tamanho, is_global);
            if(!is_global) printf("\taddiu $sp, $sp, -%d\n", 4 * tamanho);
        }
        cg_ListVar(u->f[1], tab, tipo, is_global);
    }
}

void cg_ListaDeclVar(Node* u, Tabelas* tab, int is_global) {
    if(!u) return;
    if(u->tipo == LstDeclVar_Node) {
        Prod tipo = u->f[1]->tipo;
        cg_ListVar(u->f[0], tab, tipo, is_global);
        cg_ListaDeclVar(u->f[2], tab, is_global);
    }
}

void cg_VarSection(Node* u, Tabelas* tab, int is_global) {
    if(!u) return;
    if(u->tipo == VarSection_Node) {
        cg_ListaDeclVar(u->f[0], tab, is_global);
    }
}

void cgen_LValue(Node* u, Tabelas* tab) {
    if(u->tipo == Identificador_Node) {
        Simbolo* s = find(tab, u->lexema);
        if(!s) return;
        if(s->cat == CAT_VAR || s->cat == CAT_PARAM) {
            // Check if global
            if(s->endereco == 0 && find_local(tab->last->tab, u->lexema) == NULL) { // Simplificacao para global
                // Eh global
                printf("\tla $t2, global_%s\n", u->lexema);
            } else {
                printf("\taddiu $t2, $fp, %d\n", s->endereco);
            }
        }
    } else if(u->tipo == AcessoVetor_Node) {
        Simbolo* s = find(tab, u->f[0]->lexema);
        cgen_Expr(u->f[1], tab);
        printf("\t# Multiplica indice por 4\n");
        printf("\tli $t3, 4\n");
        printf("\tmult $s0, $t3\n");
        printf("\tmflo $t3\n");
        
        if(s->endereco == 0 && find_local(tab->last->tab, u->f[0]->lexema) == NULL) {
            printf("\tla $t2, global_%s\n", u->f[0]->lexema);
            printf("\taddu $t2, $t2, $t3\n");
        } else {
            if(s->cat == CAT_PARAM_VETOR) {
                printf("\tlw $t2, %d($fp)\n", s->endereco); // Endereco base veio como param
                printf("\taddu $t2, $t2, $t3\n");
            } else {
                printf("\taddiu $t2, $fp, %d\n", s->endereco);
                printf("\taddu $t2, $t2, $t3\n");
            }
        }
    }
}

void cgen_Expr(Node* u, Tabelas* tab) {
    if(!u) return;
    
    if(u->tipo == IntConst_Node || u->tipo == CarConst_Node) {
        int val = 0;
        if(u->tipo == IntConst_Node) val = atoi(u->lexema);
        else val = u->lexema[0];
        printf("\tli $s0, %d\n", val);
    } else if(u->tipo == Identificador_Node) {
        cgen_LValue(u, tab);
        printf("\tlw $s0, 0($t2)\n");
    } else if(u->tipo == AcessoVetor_Node) {
        cgen_LValue(u, tab);
        printf("\tlw $s0, 0($t2)\n");
    } else if(u->tipo == Call_Node || u->tipo == CallEmpty_Node) {
        int num_args = 0;
        void cgen_args(Node* args) {
            if(!args) return;
            if(args->tipo == LstExpr_Node) {
                if(args->f[1]) {
                    cgen_args(args->f[0]);
                    cgen_args(args->f[1]);
                } else {
                    cgen_args(args->f[0]);
                }
                return;
            }
            Node* expr = args;
            if(expr->tipo == Identificador_Node) {
                Simbolo* s = find(tab, expr->lexema);
                if(s && (s->cat == CAT_VETOR || s->cat == CAT_PARAM_VETOR)) {
                    // Pass reference
                    if(s->endereco == 0 && find_local(tab->last->tab, s->nome) == NULL) {
                        printf("\tla $s0, global_%s\n", s->nome); 
                    } else if(s->cat == CAT_PARAM_VETOR) {
                        printf("\tlw $s0, %d($fp)\n", s->endereco);
                    } else {
                        printf("\taddiu $s0, $fp, %d\n", s->endereco);
                    }
                } else {
                    cgen_Expr(expr, tab);
                }
            } else {
                cgen_Expr(expr, tab);
            }
            printf("\tsw $s0, 0($sp)\n");
            printf("\taddiu $sp, $sp, -4\n");
            num_args++;
        }
        
        if(u->tipo == Call_Node) cgen_args(u->f[1]);
        
        printf("\tjal func_%s\n", u->f[0]->lexema);
        if(num_args > 0) printf("\taddiu $sp, $sp, %d\n", 4 * num_args);
        printf("\tmove $s0, $v0\n"); // get ret value
        
    } else if(u->tipo == Expr_Atr_Node) {
        cgen_Expr(u->f[1], tab); // s0 = val
        printf("\tsw $s0, 0($sp)\n");
        printf("\taddiu $sp, $sp, -4\n");
        
        cgen_LValue(u->f[0], tab); // t2 = addr
        
        printf("\tlw $s0, 4($sp)\n");
        printf("\taddiu $sp, $sp, 4\n");
        
        printf("\tsw $s0, 0($t2)\n"); // salva em addr
    } else if(u->tipo >= Expr_Ou_Node && u->tipo <= Expr_Div_Node) {
        cgen_Expr(u->f[0], tab);
        printf("\tsw $s0, 0($sp)\n");
        printf("\taddiu $sp, $sp, -4\n");
        
        cgen_Expr(u->f[1], tab);
        printf("\tlw $t1, 4($sp)\n");
        printf("\taddiu $sp, $sp, 4\n");
        
        if(u->tipo == Expr_Add_Node) printf("\taddu $s0, $t1, $s0\n");
        else if(u->tipo == Expr_Sub_Node) printf("\tsubu $s0, $t1, $s0\n");
        else if(u->tipo == Expr_Mul_Node) {
            printf("\tmult $t1, $s0\n");
            printf("\tmflo $s0\n");
        } else if(u->tipo == Expr_Div_Node) {
            printf("\tdiv $t1, $s0\n");
            printf("\tmflo $s0\n");
        } else if(u->tipo == Expr_Igual_Node) {
            printf("\tseq $s0, $t1, $s0\n");
        } else if(u->tipo == Expr_Dif_Node) {
            printf("\tsne $s0, $t1, $s0\n");
        } else if(u->tipo == Expr_Menor_Node) {
            printf("\tslt $s0, $t1, $s0\n");
        } else if(u->tipo == Expr_Maior_Node) {
            printf("\tsgt $s0, $t1, $s0\n");
        } else if(u->tipo == Expr_MenorIgual_Node) {
            printf("\tsle $s0, $t1, $s0\n");
        } else if(u->tipo == Expr_MaiorIgual_Node) {
            printf("\tsge $s0, $t1, $s0\n");
        }
    }
}

void cgen_Cmd(Node* u, Tabelas* tab) {
    if(!u) return;
    if(u->tipo == LstCmd_Node) {
        cgen_Cmd(u->f[0], tab);
        cgen_Cmd(u->f[1], tab);
    } else if(u->tipo == Expr_Node) {
        cgen_Expr(u->f[0], tab);
    } else if(u->tipo == Retorne_Node) {
        cgen_Expr(u->f[0], tab);
        printf("\tmove $v0, $s0\n");
        printf("\tb Func_Epilogue_%s\n", current_func_name);
    } else if(u->tipo == Leia_Node) {
        printf("\tli $v0, 5\n");
        printf("\tsyscall\n");
        printf("\tmove $s0, $v0\n");
        
        printf("\tsw $s0, 0($sp)\n");
        printf("\taddiu $sp, $sp, -4\n");
        cgen_LValue(u->f[0], tab);
        printf("\tlw $s0, 4($sp)\n");
        printf("\taddiu $sp, $sp, 4\n");
        
        printf("\tsw $s0, 0($t2)\n");
        
    } else if(u->tipo == Escreva_Node) {
        cgen_Expr(u->f[0], tab);
        printf("\tmove $a0, $s0\n");
        printf("\tli $v0, 1\n");
        printf("\tsyscall\n");
    } else if(u->tipo == NovaLinha_Node) {
        printf("\tli $a0, 10\n");
        printf("\tli $v0, 11\n");
        printf("\tsyscall\n");
    } else if(u->tipo == EscrevaStr_Node) {
        // String constants need to be in data
        int l = new_label();
        printf("\t.data\n");
        printf("str_%d: .asciiz \"%s\"\n", l, u->f[0]->lexema);
        printf("\t.text\n");
        printf("\tla $a0, str_%d\n", l);
        printf("\tli $v0, 4\n");
        printf("\tsyscall\n");
    } else if(u->tipo == Se_Node) {
        int l_fim = new_label();
        cgen_Expr(u->f[0], tab);
        printf("\tbeq $s0, $zero, L%d\n", l_fim);
        cgen_Cmd(u->f[1], tab);
        printf("L%d:\n", l_fim);
    } else if(u->tipo == Se_Senao_Node) {
        int l_senao = new_label();
        int l_fim = new_label();
        cgen_Expr(u->f[0], tab);
        printf("\tbeq $s0, $zero, L%d\n", l_senao);
        cgen_Cmd(u->f[1], tab);
        printf("\tj L%d\n", l_fim);
        printf("L%d:\n", l_senao);
        cgen_Cmd(u->f[2], tab);
        printf("L%d:\n", l_fim);
    } else if(u->tipo == Enquanto_Node) {
        int l_ini = new_label();
        int l_fim = new_label();
        printf("L%d:\n", l_ini);
        cgen_Expr(u->f[0], tab);
        printf("\tbeq $s0, $zero, L%d\n", l_fim);
        cgen_Cmd(u->f[1], tab);
        printf("\tj L%d\n", l_ini);
        printf("L%d:\n", l_fim);
    } else if(u->tipo == Bloco_Node || u->tipo == BlocoVar_Node) {
        cgen_Bloco(u, tab);
    }
}

void cgen_Bloco(Node* u, Tabelas* tab) {
    if(!u) return;
    Tabela* t = newTabela();
    t->offset_atual = tab->last->tab->offset_atual; // Continua offset do frame
    push(tab, t);
    
    if(u->tipo == BlocoVar_Node) {
        cg_VarSection(u->f[0], tab, 0); // aloca na pilha
        cgen_Cmd(u->f[1], tab);
    } else {
        cgen_Cmd(u->f[0], tab);
    }
    
    // Restaurar pilha para offset original deste bloco (opcional mas seguro)
    // na maquina MIPS $sp deve voltar
    // Pular
    pop(tab);
}

void cgen_FuncParams(Node* u, Tabelas* tab, int* offset) {
    if(!u) return;
    if(u->tipo == LstParam_Node) {
        Node* param = u->f[0];
        Prod tipo = param->f[1]->tipo;
        
        Simbolo* s = (Simbolo*) malloc(sizeof(Simbolo));
        strcpy(s->nome, param->f[0]->lexema);
        s->tipo = tipo;
        s->cat = (param->tipo == Param_Node) ? CAT_PARAM : CAT_PARAM_VETOR;
        s->endereco = *offset;
        *offset -= 4; // Parametros vêm antes do topo, entao eles estao positivos no offset!
        // Na verdade: ret(8+4*N), arg1(8+4*(N-1)), ... argN(8) -> FP -> RA
        
        inserir_simbolo(tab->last->tab, s);
        
        cgen_FuncParams(u->f[1], tab, offset);
    }
}

void cgen_DeclFuncs(Node* u, Tabelas* tab) {
    if(!u) return;
    if(u->tipo == LstFunc_Node) {
        Node* func = u->f[0];
        char* nome = func->f[0]->lexema;
        
        printf("\n\t.text\n");
        printf("func_%s:\n", nome);
        strcpy(current_func_name, nome);
        
        // Prologue
        printf("\taddiu $sp, $sp, -4\n");
        printf("\tsw $ra, 0($sp)\n");
        printf("\taddiu $sp, $sp, -4\n");
        printf("\tsw $fp, 0($sp)\n");
        printf("\tmove $fp, $sp\n");
        
        Tabela* t = newTabela();
        push(tab, t);
        
        // Count args to set offsets correctly
        int num_args = 0;
        Node* args = func->f[1];
        while(args) { num_args++; args = args->f[1]; }
        
        int offset = 8 + 4 * num_args;
        args = func->f[1];
        while(args) {
            Node* param = args->f[0];
            Simbolo* s = (Simbolo*) malloc(sizeof(Simbolo));
            strcpy(s->nome, param->f[0]->lexema);
            s->tipo = param->f[1]->tipo;
            s->cat = (param->tipo == Param_Node) ? CAT_PARAM : CAT_PARAM_VETOR;
            offset -= 4; 
            s->endereco = offset + 4; 
            inserir_simbolo(t, s);
            args = args->f[1];
        }
        
        // Body
        cgen_Bloco(func->f[3], tab);
        
        // Epilogue
        printf("Func_Epilogue_%s:\n", current_func_name);
        
        printf("\tmove $sp, $fp\n");
        printf("\tlw $fp, 0($sp)\n");
        printf("\taddiu $sp, $sp, 4\n");
        printf("\tlw $ra, 0($sp)\n");
        printf("\taddiu $sp, $sp, 4\n");
        printf("\tjr $ra\n");
        
        pop(tab);
        cgen_DeclFuncs(u->f[1], tab);
    }
}

void generate_code(Node* root) {
    if(!root) return;
    
    Tabelas* tab = newTabelas();
    Tabela* global_tab = newTabela();
    push(tab, global_tab);
    
    // Globals
    if(root->f[0]) {
        cg_VarSection(root->f[0]->f[0], tab, 1);
    }
    
    // Jump to principal
    printf("\t.text\n");
    printf("\t.globl main\n");
    printf("main:\n");
    printf("\tj func_principal\n");
    
    // Funcs
    cgen_DeclFuncs(root->f[1], tab);
    
    // Principal
    printf("\n\t.text\n");
    printf("func_principal:\n");
    
    // Setup for main
    printf("\tmove $fp, $sp\n");
    
    cgen_Bloco(root->f[2]->f[0], tab);
    
    // Halt
    printf("\n\tli $v0, 10\n");
    printf("\tsyscall\n");
    
    pop(tab);
    free(tab);
}
