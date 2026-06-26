%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "semantico.h"

extern char *yytext;
extern int yylex();
extern FILE *yyin;
extern int yylineno;
void yyerror(char const *s);
int yylineno_aux;
Node* root;
%}

%union{
    char *lexema;
    struct Node *node;
}

%type<node> DeclVarGlobais VarSection ListaDeclVar ListVar DeclFunc ListaFuncoes
%type<node> ListaParametros ListaParametrosTail DeclPrograma Bloco Tipo ListaComando Comando
%type<node> Expr LValueExpr OrExpr AndExpr EqExpr DesigExpr AddExpr MulExpr UnExpr PrimExpr ListExpr

%token GLOBAL FUNCAO PRINCIPAL INT CAR RETORNE LEIA ESCREVA NOVALINHA SE ENTAO SENAO FIMSE ENQUANTO
%token <lexema> IDENTIFICADOR CADEIACARACTERES CARCONST INTCONST
%token ATRIBUICAO OU E IGUAL DIFERENTE MAIORIGUAL MENORIGUAL

%start Programa

%%

Programa : DeclVarGlobais DeclFunc DeclPrograma { root = newNode3(Programa_Node, NULL, $1, $2, $3); }
;

DeclVarGlobais : GLOBAL VarSection { $$ = newNode1(DeclVarGlobais_Node, NULL, $2); }
               | /* vazio */ { $$ = NULL; }
;

VarSection : '[' ListaDeclVar ']' { $$ = newNode1(VarSection_Node, NULL, $2); }
;

ListaDeclVar : ListVar ':' Tipo ';' ListaDeclVar { $$ = newNode3(LstDeclVar_Node, NULL, $1, $3, $5); }
             | ListVar ':' Tipo ';' { $$ = newNode2(LstDeclVar_Node, NULL, $1, $3); }
;

ListVar : IDENTIFICADOR ',' ListVar { 
            Node* id = newNode0(Identificador_Node, $1);
            $$ = newNode2(ListVar_Node, NULL, id, $3);
        }
        | IDENTIFICADOR '[' INTCONST ']' ',' ListVar {
            Node* id = newNode0(Identificador_Node, $1);
            Node* tam = newNode0(IntConst_Node, $3);
            Node* vetor = newNode2(DeclVetor_Node, NULL, id, tam);
            $$ = newNode2(ListVar_Node, NULL, vetor, $6);
        }
        | IDENTIFICADOR {
            Node* id = newNode0(Identificador_Node, $1);
            $$ = newNode1(ListVar_Node, NULL, id);
        }
        | IDENTIFICADOR '[' INTCONST ']' {
            Node* id = newNode0(Identificador_Node, $1);
            Node* tam = newNode0(IntConst_Node, $3);
            Node* vetor = newNode2(DeclVetor_Node, NULL, id, tam);
            $$ = newNode1(ListVar_Node, NULL, vetor);
        }
;

DeclFunc : FUNCAO '[' IDENTIFICADOR '(' ListaParametros ')' ':' Tipo Bloco ListaFuncoes ']' {
            Node* id = newNode0(Identificador_Node, $3);
            Node* func = newNode4(DeclFunc_Node, NULL, id, $5, $8, $9);
            $$ = newNode2(LstFunc_Node, NULL, func, $10);
         }
         | /* vazio */ { $$ = NULL; }
;

ListaFuncoes : IDENTIFICADOR '(' ListaParametros ')' ':' Tipo Bloco ListaFuncoes {
                Node* id = newNode0(Identificador_Node, $1);
                Node* func = newNode4(DeclFunc_Node, NULL, id, $3, $6, $7);
                $$ = newNode2(LstFunc_Node, NULL, func, $8);
             }
             | /* vazio */ { $$ = NULL; }
;

ListaParametros : ListaParametrosTail { $$ = $1; }
                | /* vazio */ { $$ = NULL; }
;

ListaParametrosTail : IDENTIFICADOR ':' Tipo {
                        Node* id = newNode0(Identificador_Node, $1);
                        Node* param = newNode2(Param_Node, NULL, id, $3);
                        $$ = newNode1(LstParam_Node, NULL, param);
                    }
                    | IDENTIFICADOR '[' ']' ':' Tipo {
                        Node* id = newNode0(Identificador_Node, $1);
                        Node* param = newNode2(ParamVetor_Node, NULL, id, $5);
                        $$ = newNode1(LstParam_Node, NULL, param);
                    }
                    | IDENTIFICADOR ':' Tipo ',' ListaParametrosTail {
                        Node* id = newNode0(Identificador_Node, $1);
                        Node* param = newNode2(Param_Node, NULL, id, $3);
                        $$ = newNode2(LstParam_Node, NULL, param, $5);
                    }
                    | IDENTIFICADOR '[' ']' ':' Tipo ',' ListaParametrosTail {
                        Node* id = newNode0(Identificador_Node, $1);
                        Node* param = newNode2(ParamVetor_Node, NULL, id, $5);
                        $$ = newNode2(LstParam_Node, NULL, param, $7);
                    }
;

DeclPrograma : PRINCIPAL Bloco { $$ = newNode1(DeclPrograma_Node, NULL, $2); }
;

Bloco : '{' ListaComando '}' { $$ = newNode1(Bloco_Node, NULL, $2); }
      | VarSection '{' ListaComando '}' { $$ = newNode2(BlocoVar_Node, NULL, $1, $3); }
;

Tipo : INT { $$ = newNode0(TipoINT_Node, NULL); }
     | CAR { $$ = newNode0(TipoCAR_Node, NULL); }
;

ListaComando : Comando { $$ = newNode1(LstCmd_Node, NULL, $1); }
             | Comando ListaComando { $$ = newNode2(LstCmd_Node, NULL, $1, $2); }
;

Comando : ';' { $$ = newNode0(CmdVazio_Node, NULL); }
        | Expr ';' { $$ = newNode1(Expr_Node, NULL, $1); }
        | RETORNE Expr ';' { $$ = newNode1(Retorne_Node, NULL, $2); }
        | LEIA LValueExpr ';' { $$ = newNode1(Leia_Node, NULL, $2); }
        | ESCREVA Expr ';' { $$ = newNode1(Escreva_Node, NULL, $2); }
        | ESCREVA CADEIACARACTERES ';' { 
            Node* cad = newNode0(CadeiaCar_Node, $2);
            $$ = newNode1(EscrevaStr_Node, NULL, cad); 
        }
        | NOVALINHA ';' { $$ = newNode0(NovaLinha_Node, NULL); }
        | SE '(' Expr ')' ENTAO Comando FIMSE { $$ = newNode2(Se_Node, NULL, $3, $6); }
        | SE '(' Expr ')' ENTAO Comando SENAO Comando FIMSE { $$ = newNode3(Se_Senao_Node, NULL, $3, $6, $8); }
        | ENQUANTO '(' Expr ')' Comando { $$ = newNode2(Enquanto_Node, NULL, $3, $5); }
        | Bloco { $$ = $1; }
;

Expr : LValueExpr ATRIBUICAO Expr { $$ = newNode2(Expr_Atr_Node, NULL, $1, $3); }
     | OrExpr { $$ = $1; }
;

LValueExpr : IDENTIFICADOR '[' Expr ']' {
                Node* id = newNode0(Identificador_Node, $1);
                $$ = newNode2(AcessoVetor_Node, NULL, id, $3);
           }
           | IDENTIFICADOR { $$ = newNode0(Identificador_Node, $1); }
;

OrExpr : OrExpr OU AndExpr { $$ = newNode2(Expr_Ou_Node, NULL, $1, $3); }
       | AndExpr { $$ = $1; }
;

AndExpr : AndExpr E EqExpr { $$ = newNode2(Expr_E_Node, NULL, $1, $3); }
        | EqExpr { $$ = $1; }
;

EqExpr : EqExpr IGUAL DesigExpr { $$ = newNode2(Expr_Igual_Node, NULL, $1, $3); }
       | EqExpr DIFERENTE DesigExpr { $$ = newNode2(Expr_Dif_Node, NULL, $1, $3); }
       | DesigExpr { $$ = $1; }
;

DesigExpr : DesigExpr '<' AddExpr { $$ = newNode2(Expr_Menor_Node, NULL, $1, $3); }
          | DesigExpr '>' AddExpr { $$ = newNode2(Expr_Maior_Node, NULL, $1, $3); }
          | DesigExpr MAIORIGUAL AddExpr { $$ = newNode2(Expr_MaiorIgual_Node, NULL, $1, $3); }
          | DesigExpr MENORIGUAL AddExpr { $$ = newNode2(Expr_MenorIgual_Node, NULL, $1, $3); }
          | AddExpr { $$ = $1; }
;

AddExpr : AddExpr '+' MulExpr { $$ = newNode2(Expr_Add_Node, NULL, $1, $3); }
        | AddExpr '-' MulExpr { $$ = newNode2(Expr_Sub_Node, NULL, $1, $3); }
        | MulExpr { $$ = $1; }
;

MulExpr : MulExpr '*' UnExpr { $$ = newNode2(Expr_Mul_Node, NULL, $1, $3); }
        | MulExpr '/' UnExpr { $$ = newNode2(Expr_Div_Node, NULL, $1, $3); }
        | UnExpr { $$ = $1; }
;

UnExpr : '-' PrimExpr { $$ = newNode1(Expr_Minus_Node, NULL, $2); }
       | '!' PrimExpr { $$ = newNode1(Expr_Neg_Node, NULL, $2); }
       | PrimExpr { $$ = $1; }
;

PrimExpr : IDENTIFICADOR '(' ListExpr ')' {
                Node* id = newNode0(Identificador_Node, $1);
                $$ = newNode2(Call_Node, NULL, id, $3);
         }
         | IDENTIFICADOR '(' ')' {
                Node* id = newNode0(Identificador_Node, $1);
                $$ = newNode1(CallEmpty_Node, NULL, id);
         }
         | IDENTIFICADOR '[' Expr ']' {
                Node* id = newNode0(Identificador_Node, $1);
                $$ = newNode2(AcessoVetor_Node, NULL, id, $3);
         }
         | IDENTIFICADOR { $$ = newNode0(Identificador_Node, $1); }
         | CARCONST { $$ = newNode0(CarConst_Node, $1); }
         | INTCONST { $$ = newNode0(IntConst_Node, $1); }
         | '(' Expr ')' { $$ = $2; }
;

ListExpr : Expr { $$ = newNode1(LstExpr_Node, NULL, $1); }
         | ListExpr ',' Expr { $$ = newNode2(LstExpr_Node, NULL, $1, $3); }
;

%%

int main(int argc, char **argv){
    if(argc != 2) yyerror("Uso incorreto do compilador\nUso correto: ./g-v2 nome_arquivo\n");
    yyin = fopen(argv[1], "r");
    if(!yyin) yyerror("Arquivo nao pode ser aberto\n");
    int x = yyparse();
    int erro = semantic(root);
    if(!erro){
        printf("Codigo correto!\n");
    }
    limpa(root);
    return x;
}

void yyerror(char const *s){
    printf("ERRO: %s, na linha %d\n", s, yylineno);
    exit(1);
}
