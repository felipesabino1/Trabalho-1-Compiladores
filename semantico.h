#ifndef __SEMANTICO_H__
#define __SEMANTICO_H__

#include "tipos.h"
#include "tabelas.h"

extern void void yyerror(char const *s);

typedef void(*func_ptr)(Node*,Tabelas*)

func_ptr func[] = {
    // Bloco
    
    // Declaracoes
    
    // Tipo
    
    
    // Comandos
    
    // Expr
    
    // Tokens
    
};

void ()

void semantic(Node* root);
void dfs(Node* u, Tabelas* tab);

void semanticBlocoVar(Node* u, Tabelas *tab);

#endif