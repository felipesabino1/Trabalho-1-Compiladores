#ifndef __TIPOS_H__
#define __TIPOS_H__

typedef enum {
    Programa_Node = 0,
    DeclVarGlobais_Node,
    VarSection_Node,
    LstDeclVar_Node,
    ListVar_Node,
    DeclVetor_Node,
    DeclFunc_Node,
    LstFunc_Node,
    LstParam_Node,
    Param_Node,
    ParamVetor_Node,
    DeclPrograma_Node,
    Bloco_Node,
    BlocoVar_Node,
    TipoINT_Node,
    TipoCAR_Node,
    LstCmd_Node,
    CmdVazio_Node,
    Retorne_Node,
    Leia_Node,
    Escreva_Node,
    EscrevaStr_Node,
    NovaLinha_Node,
    Se_Node,
    Se_Senao_Node,
    Enquanto_Node,
    Expr_Node, // for Expr ';'
    Expr_Atr_Node,
    Expr_Ou_Node,
    Expr_E_Node,
    Expr_Igual_Node,
    Expr_Dif_Node,
    Expr_Menor_Node,
    Expr_Maior_Node,
    Expr_MenorIgual_Node,
    Expr_MaiorIgual_Node,
    Expr_Add_Node,
    Expr_Sub_Node,
    Expr_Mul_Node,
    Expr_Div_Node,
    Expr_Minus_Node,
    Expr_Neg_Node,
    Call_Node,
    CallEmpty_Node,
    AcessoVetor_Node,
    Identificador_Node,
    CarConst_Node,
    IntConst_Node,
    CadeiaCar_Node,
    LstExpr_Node
} Prod;

typedef struct Node {
    Prod tipo;
    int linha;
    char *lexema;
    struct Node *f[4];
} Node;

Node* newNode0(Prod tipo, char* lexema);
Node* newNode1(Prod tipo, char* lexema, Node* f1);
Node* newNode2(Prod tipo, char* lexema, Node* f1, Node* f2);
Node* newNode3(Prod tipo, char* lexema, Node* f1, Node* f2, Node* f3);
Node* newNode4(Prod tipo, char* lexema, Node* f1, Node* f2, Node* f3, Node* f4);

void limpa(Node* u);

#endif
