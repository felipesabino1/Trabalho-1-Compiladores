#ifndef __SEMANTICO_H__
#define __SEMANTICO_H__

#include "tabela.h"
#include "tipos.h"

extern void yyerror(char const *s);

int semantic(Node* root);
void dfs(Node* u, Tabelas* tab, Prod current_func_type);
Prod semantic_Expr(Node* u, Tabelas* tab);

#endif
