#ifndef __SEMANTICO_H__
#define __SEMANTICO_H__

#include "tabela.h"
#include "tipos.h"

extern void yyerror(char const *s);

void semantic(Node* root);
void dfs(Node* u, Tabelas* tab);

// Criar variaveis
void semanticVarSection(Node* u, Tabelas* tab);
void semanticLstDeclVar(Node* u, Tabelas* tab);
void semanticDeclVar(Node* u, Tabelas* tab, Prod tipo);

//Expr intermediarias (do parser)
Prod inter_expr(Node* u, Tabelas* tab);
Prod inter_orexpr(Node* u, Tabelas* tab);
Prod inter_andexpr(Node* u, Tabelas* tab);
Prod inter_eqexpr(Node* u, Tabelas* tab);
Prod inter_desigexpr(Node* u, Tabelas* tab);
Prod inter_addexpr(Node* u, Tabelas* tab);
Prod inter_mulexpr(Node* u, Tabelas* tab);
Prod inter_unexpr(Node* u, Tabelas* tab);
Prod inter_primexpr(Node* u, Tabelas* tab);

//Expr (do prod)
Prod semanticExpr(Node* u, Tabelas*tab);
Prod semanticExpr_Atr(Node *u, Tabelas* tab);
Prod semanticExpr_Ou(Node *u, Tabelas* tab);
Prod semanticExpr_E(Node*u, Tabelas* tab);
Prod semanticExpr_Igual(Node*u, Tabelas* tab);
Prod semanticExpr_Dif(Node*u, Tabelas* tab);
Prod semanticExpr_Menor(Node*u, Tabelas* tab);
Prod semanticExpr_Maior(Node*u, Tabelas* tab);
Prod semanticExpr_MenorIgual(Node*u, Tabelas* tab);
Prod semanticExpr_MaiorIgual(Node*u, Tabelas* tab);
Prod semanticExpr_Add(Node*u, Tabelas* tab);
Prod semanticExpr_Sub(Node*u, Tabelas* tab);
Prod semanticExpr_Mul(Node*u, Tabelas* tab);
Prod semanticExpr_Div(Node*u, Tabelas* tab);
Prod semanticExpr_Minus(Node*u, Tabelas* tab);
Prod semanticExpr_Neg(Node*u, Tabelas* tab);

//Tokens
Prod semanticIdentificador(Node*u, Tabelas * tab);
Prod semanticCarConst(Node*u, Tabelas * tab);
Prod semanticIntConst(Node*u, Tabelas * tab);
Prod semanticCadeiaCar(Node*u, Tabelas * tab);

#endif