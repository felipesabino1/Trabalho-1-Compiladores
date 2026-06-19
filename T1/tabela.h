#ifndef __TABELA_SIMBOLOS_H__
#define __TABELA_SIMBOLOS_H__

#include "tipos.h"

typedef struct tabela{
    int* tab; 
}Tabela;

typedef struct No{
    Tabela* tab;
    struct No* prev;
}No;

typedef struct tabelas{
    No* last;
    int tam;
} Tabelas;

int hash(char *s);

Tabela* newTabela();
No* newNode(Tabela* t);

void addVar(Tabela* t, char* var, Prod tipo);

Tabelas* newTabelas();
void pop(Tabelas* t);
void push(Tabelas* t, Tabela* tab);

Prod find(Tabelas* tab, char* variavel);

#endif