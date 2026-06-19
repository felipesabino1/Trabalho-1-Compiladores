#include "tabela.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern void yyerror(const char* s);

const int mod=100003;
const int x_hash = 33;

int hash(char* s){  
    int h=s[0];
    for(int i=1;s[i]; i++){
        h = (1ll * h * x_hash + s[i]) % mod;
    }
    return h;
}

Tabela* newTabela(){
    Tabela* t = (Tabela*) malloc(sizeof(Tabela));
    if(!t) yyerror("sem espaco de memoria");
    t->tab = (Simbolo**) malloc(sizeof(Simbolo*) * (mod+1));
    for(int i=0;i<mod;i++) t->tab[i] = NULL;
    t->offset_atual = 0;
    return t;
}

No* newNodeTabela(Tabela* t){
    No* no = (No*) malloc(sizeof(No));
    if(!no) yyerror("sem espaco de memoria");
    no->tab=t;
    no->prev=NULL;
    return no;
}

Tabelas* newTabelas(){
    Tabelas* tab = (Tabelas*) malloc(sizeof(Tabelas));
    if(!tab) yyerror("sem espaco");
    tab->last=NULL;
    tab->tam=0;
    return tab;
}

void push(Tabelas* tab, Tabela* t){
    if(!tab) yyerror("tabelas nao existe");
    No* no = newNodeTabela(t);
    no->prev=tab->last;
    tab->last=no;
    tab->tam++;
}

void pop(Tabelas* t){
    if(!t || t->tam==0) yyerror("tabelas vazia");
    No* no = t->last;
    t->last=no->prev;
    // free memory para simbolos aqui seria ideal
    free(no);
    t->tam--;
}

Simbolo* find_local(Tabela* t, char* variavel){
    int h = hash(variavel);
    Simbolo* at = t->tab[h];
    while(at){
        if(strcmp(at->nome, variavel) == 0) return at;
        at = at->prox;
    }
    return NULL;
}

Simbolo* find(Tabelas* tab, char* variavel){
    No* at = tab->last;
    while(at){
        Simbolo* s = find_local(at->tab, variavel);
        if(s) return s;
        at = at->prev;
    }
    return NULL;
}

void inserir_simbolo(Tabela* t, Simbolo* s) {
    int h = hash(s->nome);
    s->prox = t->tab[h];
    t->tab[h] = s;
}

void addVar(Tabela* t, char* var, Prod tipo, int posicao){
    if(find_local(t, var)) yyerror("variavel redeclarada no mesmo escopo");
    Simbolo* s = (Simbolo*) malloc(sizeof(Simbolo));
    strcpy(s->nome, var);
    s->tipo = tipo;
    s->cat = CAT_VAR;
    s->endereco = posicao;
    inserir_simbolo(t, s);
}

void addVetor(Tabela* t, char* var, Prod tipo, int tamanho, int posicao){
    if(find_local(t, var)) yyerror("vetor redeclarado no mesmo escopo");
    Simbolo* s = (Simbolo*) malloc(sizeof(Simbolo));
    strcpy(s->nome, var);
    s->tipo = tipo;
    s->cat = CAT_VETOR;
    s->tamanho = tamanho;
    s->endereco = posicao;
    inserir_simbolo(t, s);
}

void addFunc(Tabela* t, char* var, Prod tipo, int num_params, ParamInfo* params){
    if(find_local(t, var)) yyerror("funcao redeclarada no mesmo escopo");
    Simbolo* s = (Simbolo*) malloc(sizeof(Simbolo));
    strcpy(s->nome, var);
    s->tipo = tipo;
    s->cat = CAT_FUNC;
    s->num_params = num_params;
    s->params = params;
    inserir_simbolo(t, s);
}

void addParam(Tabela* t, char* var, Prod tipo, int posicao, Categoria cat){
    if(find_local(t, var)) yyerror("parametro redeclarado no mesmo escopo");
    Simbolo* s = (Simbolo*) malloc(sizeof(Simbolo));
    strcpy(s->nome, var);
    s->tipo = tipo;
    s->cat = cat;
    s->endereco = posicao;
    inserir_simbolo(t, s);
}
