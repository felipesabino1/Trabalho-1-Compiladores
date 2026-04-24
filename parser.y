%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

extern char *yytext;
extern int yylex();
extern FILE *yyin;
extern int yylineno;
void yyerror(char const *s);
Node* root;
%}

%union{
    char *lexema;
    struct Node *node;
}

%type<node> bloco varsection listadeclvar declvar tipo listacomando comando expr orexpr andexpr eqexpr desigexpr addexpr mulexpr unexpr primexpr

%token PRINCIPAL <lexema>IDENTIFICADOR INT CAR LEIA ESCREVA NOVALINHA SE ENTAO SENAO FIMSE ENQUANTO <lexema>CADEIACARACTERES OU E IGUAL DIFERENTE MAIORIGUAL MENORIGUAL <lexema>CARCONST <lexema>INTCONST

%start programa

%%

programa    : declrprograma
;

declrprograma   : PRINCIPAL bloco   {root = $2;}
;

bloco   : '{' listacomando '}'              {$$ = newNode1(Bloco,NULL,$2);}
        | varsection '{' listacomando '}'   {$$ = newNode2(BlocoVar,NULL,$1,$3);}
;

varsection  : '{' listadeclvar '}'  {$$ = $2;}
;

listadeclvar    : IDENTIFICADOR declvar ':' tipo ';' listadeclvar   {
    Node* aux = newNode0(Identificador,$1);
    aux->linha = $2->linha;
    $$ = newNode4(LstDeclVar,NULL,aux,$2,$4,$6);
}
                | IDENTIFICADOR declvar ':' tipo ';'                {
    Node* aux = newNode0(Identificador,$1);
    aux->linha = $2->linha;
    $$ = newNode3(LstDeclVar,NULL,aux,$2,$4);
}
;

declvar :                           {$$ = NULL;}
        | ',' IDENTIFICADOR declvar {$$ = newNode2(DeclVar,NULL,newNode0(Identificador,$2),$3);}
;

tipo    : INT   {$$ = newNode0(TipoINT,NULL);}
        | CAR   {$$ = newNode0(TipoCAR,NULL);}
;

listacomando    : comando               {$$ = newNode1(LstCmd,NULL,$1);}
                | comando listacomando  {$$ = newNode2(LstCmd,NULL,$1,$2);}
;

comando : ';'                                                           {$$ = NULL;}
        | expr ';'                                                      {$$ = newNode1(Expr,NULL,$1);}
        | LEIA IDENTIFICADOR ';'                                        {$$ = newNode1(Leia,NULL,newNode0(Identificador,$2));}
        | ESCREVA expr ';'                                              {$$ = newNode1(Escreva,NULL,$2);}
        | ESCREVA CADEIACARACTERES ';'                                  {$$ = newNode1(Escreva,NULL,newNode0(CadeiaCar,$2));}
        | NOVALINHA ';'                                                 {$$ = NULL;}
        | SE '(' expr ')' ENTAO comando FIMSE                           {$$ = newNode2(Se,NULL,$3,$6);}
        | SE '(' expr ')' ENTAO comando SENAO comando FIMSE             {$$ = newNode3(Se_Senao,NULL,$3,$6,$8);}
        | ENQUANTO '(' expr ')' comando                                 {$$ = newNode2(Enquanto,NULL,$3,$5);}
        | bloco                                                         {$$ = $1;}
;

expr    : orexpr                {$$ = $1;}
        | IDENTIFICADOR '=' expr {$$ = newNode2(Expr_Atr,NULL,newNode0(Identificador,$1),$3);}
;

orexpr  : orexpr OU andexpr {$$ = newNode2(Expr_Ou,NULL,$1,$3);}
        | andexpr           {$$ = $1;}
;

andexpr : andexpr E eqexpr  {$$ = newNode2(Expr_E,NULL,$1,$3);}
        | eqexpr            {$$ = $1;}
;

eqexpr  : eqexpr IGUAL desigexpr    {$$ = newNode2(Expr_Igual,NULL,$1,$3);}
        | eqexpr DIFERENTE desigexpr {$$ = newNode2(Expr_Dif,NULL,$1,$3);}
        | desigexpr                  {$$ = $1;}
;

desigexpr   : desigexpr '<' addexpr         {$$ = newNode2(Expr_Menor,NULL,$1,$3);}
            | desigexpr '>' addexpr         {$$ = newNode2(Expr_Maior,NULL,$1,$3);}
            | desigexpr MAIORIGUAL addexpr  {$$ = newNode2(Expr_MaiorIgual,NULL,$1,$3);}
            | desigexpr MENORIGUAL addexpr  {$$ = newNode2(Expr_MenorIgual,NULL,$1,$3);}
            | addexpr                       {$$ = $1;}
;

addexpr : addexpr '+' mulexpr   {$$ = newNode2(Expr_Add,NULL,$1,$3);}
        | addexpr '-' mulexpr   {$$ = newNode2(Expr_Sub,NULL,$1,$3);}
        | mulexpr               {$$ = $1;}
;

mulexpr : mulexpr '*' unexpr    {$$ = newNode2(Expr_Mul,NULL,$1,$3);}
        | mulexpr '/' unexpr    {$$ = newNode2(Expr_Div,NULL,$1,$3);}
        | unexpr                {$$ = $1;}
;

unexpr  : '-' primexpr  {$$ = newNode1(Expr_Minus,NULL,$2);}
        | '!' primexpr  {$$ = newNode1(Expr_Neg,NULL,$2);}
        | primexpr      {$$ = $1;}
;

primexpr    : IDENTIFICADOR {$$ = newNode0(Identificador,$1);}
            | CARCONST      {$$ = newNode0(CarConst,$1);}
            | INTCONST      {$$ = newNode0(IntConst,$1);}
            | '(' expr ')'  {$$ = $2;}
;

%%

int main(int argc, char **argv){
    if(argc != 2) yyerror("Uso incorreto do compilador\nUso correto: ./g-v1 nome_arquivo\n");
    yyin = fopen(argv[1], "r");
    if(!yyin) yyerror("Arquivo nao pode ser aberto\n");
    int x = yyparse();
    limpa(root);
    return x;
}

void yyerror(char const *s){
    printf("ERRO: %s, na linha %d\n", s, yylineno);
    exit(1);
}