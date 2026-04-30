#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

extern int yylineno;
extern void yyerror(char const* s);

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

void limpa(Node* u){
    if(u == NULL) return;
    for(int i=0; i<4; i++) limpa(u->f[i]);
    if(u->lexema) free(u->lexema);
    free(u);
}