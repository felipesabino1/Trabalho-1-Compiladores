#include "semantico.h"
#include "tabela.h"

#include <stdio.h>
#include "tipos.h"


extern void yyerror(const char*);
extern int yylineno;

void semantic(Node* root){
    Tabelas* tab = newTabelas();
    dfs(root,tab);
}

char* tipoLiteral[] = {
    "Bloco","BlocoVar",
    "LstDeclVar","DeclVar",
    "TipoINT","TipoCAR",
    "LstCmd","Leia","Escreva","Se","Se_Senao","Enquanto",
    "Expr","Expr_Atr","Expr_Ou","Expr_E","Expr_Igual","Expr_Dif","Expr_Menor",
    "Expr_Maior","Expr_MenorIgual","Expr_MaiorIgual","Expr_Add","Expr_Sub",
    "Expr_Mul","Expr_Div","Expr_Minus","Expr_neg",
    "Identificador","CarConst","IntConst","CadeiaCar"
};

void dfs(Node* u, Tabelas* tab){
    if(!u) return;
    yylineno = u->linha;
    // printf("%s\n",tipoLiteral[u->tipo]);
    if(u->tipo == Bloco){
        dfs(u->f[0],tab);
    }else if(u->tipo == BlocoVar){
        semanticVarSection(u->f[0],tab);
        dfs(u->f[1],tab);
        pop(tab);
    }else if(u->tipo == LstCmd){
        dfs(u->f[0],tab);
        dfs(u->f[1],tab);
    }else if(u->tipo == Leia){
        // nao preciso verificar nada
    }else if(u->tipo == Escreva){
        if(u->f[0]->tipo != CadeiaCar) semanticExpr(u->f[0],tab);
    }else if(u->tipo == Se){
        semanticExpr(u->f[0],tab);
        dfs(u->f[1],tab);
    }else if(u->tipo == Se_Senao){
        semanticExpr(u->f[0],tab);
        dfs(u->f[1],tab);
        dfs(u->f[2],tab);
    }else if(u->tipo == Enquanto){
        semanticExpr(u->f[0],tab);
        dfs(u->f[1],tab);
    }else if(u->tipo == Expr){
        semanticExpr(u->f[0],tab);
    }else yyerror("compilador esta errado");
}

// Criar variaveis
void semanticVarSection(Node* u, Tabelas* tab){
    if(!u) return;
    push(tab,newTabela());
    semanticLstDeclVar(u,tab);
}
void semanticLstDeclVar(Node* u, Tabelas* tab){
    if(!u) return;
    Prod tipo = (u->f[2])->tipo;
    yylineno = u->linha;
    addVar(tab->last->tab,u->f[0]->lexema,tipo);
    semanticDeclVar(u->f[1],tab,tipo);
    semanticLstDeclVar(u->f[3],tab);
}
void semanticDeclVar(Node* u, Tabelas* tab, Prod tipo){
    if(!u) return;
    yylineno = u->linha;
    addVar(tab->last->tab,u->f[0]->lexema,tipo);
    semanticDeclVar(u->f[1],tab,tipo);
}

//Expr intermediarias (do parser)
Prod inter_expr(Node*u, Tabelas* tab){
    // printf("%s\n", __func__);
    if(u->tipo == Expr_Atr) return semanticExpr_Atr(u, tab);
    return inter_orexpr(u, tab);
}

Prod inter_orexpr(Node* u, Tabelas* tab){
    // printf("%s\n", __func__);
    if(u->tipo == Expr_Ou) return semanticExpr_Ou(u, tab);
    return inter_andexpr(u, tab);
}

Prod inter_andexpr(Node* u, Tabelas* tab){
    // printf("%s\n", __func__);
    if(u->tipo == Expr_E) return semanticExpr_E(u, tab);
    return inter_eqexpr(u, tab);
}

Prod inter_eqexpr(Node* u, Tabelas* tab){
    // printf("%s\n", __func__);
    if(u->tipo == Expr_Igual) return semanticExpr_Igual(u, tab);
    if(u->tipo == Expr_Dif) return semanticExpr_Dif(u, tab);
    return inter_desigexpr(u, tab);
}

Prod inter_desigexpr(Node* u, Tabelas* tab){
    // printf("%s\n", __func__);
    if(u->tipo == Expr_Menor) return semanticExpr_Menor(u, tab);
    if(u->tipo == Expr_Maior) return semanticExpr_Maior(u, tab);
    if(u->tipo == Expr_MaiorIgual) return semanticExpr_MaiorIgual(u,tab);
    if(u->tipo == Expr_MenorIgual) return semanticExpr_MenorIgual(u, tab);
    return inter_addexpr(u, tab); 
}

Prod inter_addexpr(Node* u, Tabelas* tab){
    // printf("%s\n", __func__);
    if(u->tipo == Expr_Add) return semanticExpr_Add(u, tab);
    if(u->tipo == Expr_Sub) return semanticExpr_Sub(u, tab);
    return inter_mulexpr(u, tab);
}

Prod inter_mulexpr(Node* u, Tabelas* tab){
    if(u->tipo == Expr_Mul) return semanticExpr_Mul(u, tab);
    if(u->tipo == Expr_Div) return semanticExpr_Div(u, tab);
    return inter_unexpr(u, tab);
}

Prod inter_unexpr(Node* u, Tabelas* tab){
    if(u->tipo == Expr_Minus) return semanticExpr_Minus(u, tab);
    if(u->tipo == Expr_Neg) return semanticExpr_Neg(u, tab);
    return inter_primexpr(u,tab);
}

Prod inter_primexpr(Node* u, Tabelas* tab){
    // printf("%s\n", __func__);
    // printf("%s\n", tipoLiteral[u->tipo]);
    // if(u->tipo == Identificador) printf("lexema: %s\n", u->lexema);
    // printf("\n\n");
    if(u->tipo == Identificador) {
        Prod cara = semanticIdentificador(u, tab);
        // printf("cara = %s\n", tipoLiteral[cara]);
        return cara;
    }
    if(u->tipo == CarConst) return semanticCarConst(u, tab);
    if(u->tipo == IntConst) return semanticIntConst(u, tab);
    return inter_expr(u, tab);
}

//Expr (do prod)
Prod semanticExpr(Node* u, Tabelas*tab){
    return inter_expr(u, tab);
}

Prod semanticExpr_Atr(Node *u, Tabelas* tab){
    // printf("Atribuicao\n");
    // printf("%p %p\n",u->f[0],u->f[1]);
    char* var_esq = u->f[0]->lexema;
    Prod tipo_esq = find(tab, var_esq);
    // printf("foi\n");
    if(!tipo_esq) yyerror("variavel nao declarada");

    Prod tipo_dir = inter_expr(u->f[1], tab);
    
    if(tipo_esq != tipo_dir) yyerror("atribuicao com tipos diferentes");
    
    return tipo_dir;
}

Prod semanticExpr_Ou(Node* u, Tabelas* tab){
    Prod tipo_esq = inter_orexpr(u->f[0], tab);
    Prod tipo_dir = inter_andexpr(u->f[1], tab);

    if(tipo_esq != tipo_dir) yyerror("operacao com tipos distintos");

    return TipoINT;
}

Prod semanticExpr_E(Node*u, Tabelas* tab){
    Prod tipo_esq = inter_andexpr(u->f[0],tab);
    Prod tipo_dir = inter_eqexpr(u->f[1],tab);
    if(tipo_esq != tipo_dir) yyerror("operacao com tipos distintos");
    return TipoINT;
}

Prod semanticExpr_Igual(Node*u, Tabelas* tab){
    Prod tipo_esq = inter_eqexpr(u->f[0],tab);
    Prod tipo_dir = inter_desigexpr(u->f[1],tab);
    if(tipo_esq != tipo_dir) yyerror("operacao com tipos distintos");
    return TipoINT;
}

Prod semanticExpr_Dif(Node*u, Tabelas* tab){
    Prod tipo_esq = inter_eqexpr(u->f[0],tab);
    Prod tipo_dir = inter_desigexpr(u->f[1],tab);
    if(tipo_esq != tipo_dir) yyerror("operacao com tipos distintos");
    return TipoINT;
}

Prod semanticExpr_Menor(Node*u, Tabelas* tab){
    Prod tipo_esq = inter_desigexpr(u->f[0],tab);
    Prod tipo_dir = inter_addexpr(u->f[1],tab);
    if(tipo_esq != tipo_dir) yyerror("operacao com tipos distintos");
    return TipoINT;
}

Prod semanticExpr_Maior(Node*u, Tabelas* tab){
    Prod tipo_esq = inter_desigexpr(u->f[0],tab);
    Prod tipo_dir = inter_addexpr(u->f[1],tab);
    if(tipo_esq != tipo_dir) yyerror("operacao com tipos distintos");
    return TipoINT;    
}

Prod semanticExpr_MenorIgual(Node*u, Tabelas* tab){

    // printf("%s\n", tipoLiteral[u->tipo]);

    Prod tipo_esq = inter_desigexpr(u->f[0],tab);
    Prod tipo_dir = inter_addexpr(u->f[1],tab);
    if(tipo_esq != tipo_dir) yyerror("operacao com tipos distintos");
    return TipoINT;
}

Prod semanticExpr_MaiorIgual(Node*u, Tabelas* tab){
    Prod tipo_esq = inter_desigexpr(u->f[0],tab);
    Prod tipo_dir = inter_addexpr(u->f[1],tab);
    if(tipo_esq != tipo_dir) yyerror("operacao com tipos distintos");
    return TipoINT;    
}

Prod semanticExpr_Add(Node*u, Tabelas* tab){
    Prod tipo_esq = inter_addexpr(u->f[0],tab);
    Prod tipo_dir = inter_mulexpr(u->f[1],tab);
    if(tipo_esq != tipo_dir) yyerror("operacao com tipos distintos");
    if(tipo_esq != TipoINT) yyerror("operacao aritmetica feita com um tipo nao inteiro");
    return TipoINT;
}

Prod semanticExpr_Sub(Node*u, Tabelas* tab){
    Prod tipo_esq = inter_addexpr(u->f[0],tab);
    Prod tipo_dir = inter_mulexpr(u->f[1],tab);
    if(tipo_esq != tipo_dir) yyerror("operacao com tipos distintos");
    if(tipo_esq != TipoINT) yyerror("operacao aritmetica feita com um tipo nao inteiro");
    return TipoINT;
}

Prod semanticExpr_Mul(Node*u, Tabelas* tab){
    Prod tipo_esq = inter_mulexpr(u->f[0],tab);
    Prod tipo_dir = inter_unexpr(u->f[1],tab);
    if(tipo_esq != tipo_dir) yyerror("operacao com tipos distintos");
    if(tipo_esq != TipoINT) yyerror("operacao aritmetica feita com um tipo nao inteiro");
    return TipoINT;
}

Prod semanticExpr_Div(Node*u, Tabelas* tab){
    Prod tipo_esq = inter_mulexpr(u->f[0],tab);
    Prod tipo_dir = inter_unexpr(u->f[1],tab);
    if(tipo_esq != tipo_dir) yyerror("operacao com tipos distintos");
    if(tipo_esq != TipoINT) yyerror("operacao aritmetica feita com um tipo nao inteiro");
    return TipoINT;
}

Prod semanticExpr_Minus(Node*u, Tabelas* tab){
    Prod tipo = inter_primexpr(u->f[0], tab);
    return TipoINT;
}

Prod semanticExpr_Neg(Node*u, Tabelas* tab){
    Prod tipo = inter_primexpr(u, tab);
    return TipoINT;
}

//Tokens
Prod semanticIdentificador(Node*u, Tabelas * tab){
    return find(tab, u->lexema);
}

Prod semanticCarConst(Node*u, Tabelas * tab){
    return TipoCAR;
}

Prod semanticIntConst(Node*u, Tabelas * tab){

    // printf("\n\nINT CONST:\n");
    // printf("TIPO : %s\n", tipoLiteral[u->tipo]);
    // printf("LEXEMA: %s\n", u->lexema);

    return TipoINT;
}   

Prod semanticCadeiaCar(Node*u, Tabelas * tab){
    //n é pra ter nada
}

