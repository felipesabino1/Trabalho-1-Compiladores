#include "tabela.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern void yyerror(const char* s);

const int mod=100003;
const int x = 33;

int hash(char* s){  
    int h=s[0];
    for(int i=1;s[i]; i++){
        h = (1ll * h * x + s[i]) % mod;
    }
    return h;
}

Tabela* newTabela(){
    Tabela* t = (Tabela*) malloc(sizeof(Tabela));
    if(!t){
        yyerror("SEM ESPACO DE MEMORIA PARA ALOCACAO");
    }

    t->tab = (int*) malloc(sizeof(int) * (mod+1));
    if(!t->tab){
        yyerror("SEM ESPACO DE MEMORIA PARA ALOCACAO");
    }
    
    return t;
}

No* newNode(Tabela* t){
    No* no = (No*) malloc(sizeof(No));
    if(!no){
        yyerror("SEM ESPACO DE MEMORIA PARA ALOCACAO");
    }

    no->tab=t;
    no->prev=NULL;
}

Tabelas* newTabelas(){
    Tabelas* tab = (Tabelas*) malloc(sizeof(Tabelas));
    if(!tab){
        yyerror("SEM ESPACO DE MEMORIA PARA ALOCACAO");
    }
    tab->last=NULL;
    tab->tam=0;
}

void push(Tabelas* tab, Tabela* t){
    if(!tab){
        yyerror("TABELA NAO EXISTE");
    }

    No* no = newNode(t);
    no->prev=tab->last;

    tab->last=no;
    tab->tam++;
}

void pop(Tabelas* t){
    if(!t){
        yyerror("TABELA NAO EXISTE");
    }
    if(t->tam==0){
        yyerror("TABELA VAZIA");
    }

    No* no = t->last;
    t->last=no->prev;
    free(no);
}

int find(Tabelas* tab, char* variavel){
    int x = hash(variavel);
    No* at = tab->last;

    while(at){

        Tabela* t = at->tab;

        if(t->tab[x] != 0) return t->tab[x];

        at=at->prev;
    }

    return 0;
}