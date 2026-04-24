#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

extern int yylineno;
extern void yyerror(char const* s);
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

Node* newNode4(Prod tipo, char* lexema, Node* f1, Node* f2, Node* f3, Node* f4){
    Node* node = (Node*) malloc(sizeof(Node));
    if(!node) yyerror("SEM ESPACO DE MEMORIA PARA ALOCACAO");
    node->tipo = tipo;
    node->linha = yylineno;
    node->lexema = lexema;
    node->f[0] = f1, node->f[1] = f2, node->f[2] = f3, node->f[3] = f4;
    return node;
}

Node* newNode0(Prod tipo, char* lexema){
    return newNode4(tipo, lexema, NULL, NULL, NULL, NULL);
}
Node* newNode1(Prod tipo, char* lexema, Node* f1){
    return newNode4(tipo, lexema, f1, NULL, NULL, NULL);
}
Node* newNode2(Prod tipo, char* lexema, Node* f1, Node* f2){
    return newNode4(tipo, lexema, f1, f2, NULL, NULL);
}
Node* newNode3(Prod tipo, char* lexema, Node* f1, Node* f2, Node* f3){
    return newNode4(tipo, lexema, f1, f2, f3, NULL);
}

void dfs(Node* u){
    if(u == NULL) return;
    printf("In\n");
    printf("TIPO: %s\n",tipoLiteral[u->tipo]);
    for(int i=0; i<4; i++) dfs(u->f[i]);
    printf("Out\n");
}
void limpa(Node* u){
    if(u == NULL) return;
    for(int i=0; i<4; i++) limpa(u->f[i]);
    if(u->lexema) free(u->lexema);
    free(u);
}