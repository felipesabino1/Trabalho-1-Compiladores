#ifndef __TABELA_SIMBOLOS_H__
#define __TABELA_SIMBOLOS_H__

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

Tabelas* newTabelas();
Tabelas* pop(Tabelas* t);
Tabelas* push(Tabelas* t, Tabela* tab);

int find(Tabelas* tab, char* variavel);

#endif