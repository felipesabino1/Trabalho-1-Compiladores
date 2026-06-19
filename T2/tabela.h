#ifndef __TABELA_SIMBOLOS_H__
#define __TABELA_SIMBOLOS_H__

#include "tipos.h"

typedef enum {
    CAT_VAR,
    CAT_VETOR,
    CAT_FUNC,
    CAT_PARAM,
    CAT_PARAM_VETOR
} Categoria;

typedef struct ParamInfo {
    Prod tipo;
    Categoria cat;
    struct ParamInfo* prox;
} ParamInfo;

typedef struct Simbolo {
    char nome[128];
    Prod tipo; // TipoINT ou TipoCAR
    Categoria cat;
    int endereco; // posicao/offset
    int tamanho; // para vetores
    int num_params;
    ParamInfo* params; // para funcoes
    struct Simbolo* prox; // para a tabela hash
} Simbolo;

typedef struct tabela {
    Simbolo** tab; 
    int offset_atual; // ajuda a calcular offsets de variaveis neste escopo
} Tabela;

typedef struct No {
    Tabela* tab;
    struct No* prev;
} No;

typedef struct tabelas {
    No* last;
    int tam;
} Tabelas;

int hash(char *s);

Tabela* newTabela();
No* newNodeTabela(Tabela* t);

void inserir_simbolo(Tabela* t, Simbolo* s);
void addVar(Tabela* t, char* var, Prod tipo, int posicao);
void addVetor(Tabela* t, char* var, Prod tipo, int tamanho, int posicao);
void addFunc(Tabela* t, char* var, Prod tipo, int num_params, ParamInfo* params);
void addParam(Tabela* t, char* var, Prod tipo, int posicao, Categoria cat);

Tabelas* newTabelas();
void pop(Tabelas* t);
void push(Tabelas* t, Tabela* tab);

Simbolo* find(Tabelas* tab, char* variavel);
Simbolo* find_local(Tabela* t, char* variavel);

#endif
