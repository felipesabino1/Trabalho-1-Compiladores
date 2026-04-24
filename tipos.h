#ifndef __TIPOS_H__
#define __TIPOS_H__
typedef enum{
    // Bloco
    Bloco=0,BlocoVar,
    // Declaracoes
    LstDeclVar,DeclVar,
    // Tipo
    TipoINT,TipoCAR,
    // Comandos
    LstCmd,Leia,Escreva,Se,Se_Senao,Enquanto,
    // Expr
    Expr,Expr_Atr,Expr_Ou,Expr_E,Expr_Igual,Expr_Dif,Expr_Menor,
    Expr_Maior,Expr_MenorIgual,Expr_MaiorIgual,Expr_Add,Expr_Sub,
    Expr_Mul,Expr_Div,Expr_Minus,Expr_Neg,
    // Tokens
    Identificador,CarConst,IntConst,CadeiaCar
}Prod;

typedef struct Node{
    Prod tipo;
    int linha;
    char *lexema;
    struct Node *f[4];
}Node;

Node* newNode0(Prod tipo, char* lexema);
Node* newNode1(Prod tipo, char* lexema, Node* f1);
Node* newNode2(Prod tipo, char* lexema, Node* f1, Node* f2);
Node* newNode3(Prod tipo, char* lexema, Node* f1, Node* f2, Node* f3);
Node* newNode4(Prod tipo, char* lexema, Node* f1, Node* f2, Node* f3, Node* f4);

void dfs(Node* u);
void limpa(Node* u);

#endif