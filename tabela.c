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
        yyerror("sem espaco de memoria para alocacao");
    }

    t->tab = (int*) malloc(sizeof(int) * (mod+1));
    for(int i=0;i<mod;i++)t->tab[i]=0;

    if(!t->tab){
        yyerror("sem espaco de memoria para alocacao");
    }
    
    return t;
}

void addVar(Tabela* t, char* var, Prod tipo){
    if(!t) yyerror("tabela de simbolos nao existe");
    if(!var) yyerror("variavel nao existe");
    if(tipo != TipoINT && tipo != TipoCAR) yyerror("tipo invalido");
    int x = hash(var);
    if(t->tab[x]) yyerror("variavel redeclarada no mesmo escopo");
    t->tab[x] = tipo;
}

No* newNode(Tabela* t){
    No* no = (No*) malloc(sizeof(No));
    if(!no){
        yyerror("sem espaco de memoria para alocacao");
    }

    no->tab=t;
    no->prev=NULL;
}

Tabelas* newTabelas(){
    Tabelas* tab = (Tabelas*) malloc(sizeof(Tabelas));
    if(!tab){
        yyerror("sem espaco de memoria para alocacao");
    }
    tab->last=NULL;
    tab->tam=0;
}

void push(Tabelas* tab, Tabela* t){
    if(!tab){
        yyerror("tabela de simbolos nao existe");
    }

    No* no = newNode(t);
    no->prev=tab->last;

    tab->last=no;
    tab->tam++;
}

void pop(Tabelas* t){
    if(!t){
        yyerror("tabela de simbolos nao existe");
    }
    if(t->tam==0){
        yyerror("tabela de simbolos esta vazia");
    }

    No* no = t->last;
    t->last=no->prev;
    free(no);
}

Prod find(Tabelas* tab, char* variavel){
    int x = hash(variavel);
    No* at = tab->last;

    while(at){

        Tabela* t = at->tab;

        if(t->tab[x] != 0) return t->tab[x];

        at=at->prev;
    }

    return 0;
}