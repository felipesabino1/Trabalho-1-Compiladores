%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokens.h"
#include "tipos.h"
extern void yyerror(char const* s);
%}

 /* Definicoes */

LETRA [A-Z]|[a-z]
DIGITO [0-9]

 /* condicoes */
%x car_cond 
%x cadeia_cond
%x comentario_cond

%option yylineno

%% 

 /* tokens simples */
"{"	return '{';
"}"	return '}';
":"	return ':';
";"	return ';';
","	return ',';
"("	return '(';
")"	return ')';
"="	return '=';
"<"	return '<';
">"	return '>';
"+"	return '+';
"-"	return '-';
"*"	return '*';
"/"	return '/';
"!"	return '!';

 /* tokens complexos */
principal              	return PRINCIPAL;
int                   	return INT;
car                    	return CAR;
leia                   	return LEIA;
escreva              	return ESCREVA;
novalinha              	return NOVALINHA;
se                   	return SE;
entao                  	return ENTAO;
senao               	return SENAO;
fimse                 	return FIMSE;
enquanto              	return ENQUANTO;
"||"                   	return OU;
"&"                   	return E;
"=="                  	return IGUAL;
"!="                  	return DIFERENTE;
">="                   	return MAIORIGUAL;
"<="                   	return MENORIGUAL;
({LETRA}|_)+({LETRA}|{DIGITO}|_)*      	{
	yylval.lexema = (char*) malloc(yyleng+1);
	if(!yylval.lexema) yyerror("SEM ESPACO DE MEMORIA PARA ALOCACAO");
	strcpy(yylval.lexema,yytext);
	return IDENTIFICADOR;
}
 /* comentario */
"/*"	BEGIN(comentario_cond);
<comentario_cond>[^*\n]	/* consome o comentario */
<comentario_cond>\n 
<comentario_cond>"*"+[^*/\n]*   /* consome * que nao tem / em sequencia */
<comentario_cond><<EOF>>	    yyerror("COMENTARIO NAO TERMINA");

<comentario_cond>"*"+"/"        BEGIN(INITIAL);


 /* CADEIACARACTERES */
\"			BEGIN(cadeia_cond); 
<cadeia_cond>[^"\n]*\"	{
	BEGIN(INITIAL); 
	yytext[--yyleng] = '\0'; /* remover a ultima \" */
    yylval.lexema = (char*) malloc(yyleng+1);
    if(!yylval.lexema) yyerror("SEM ESPACO DE MEMORIA PARA ALOCACAO");
    strcpy(yylval.lexema,yytext);
	return CADEIACARACTERES;
}
<cadeia_cond>[^"\n]*(\n)+	yyerror("CADEIA DE CARACTERES OCUPA MAIS DE UMA LINHA");
<cadeia_cond><<EOF>>	    yyerror("CADEIA DE CARACTERES NAO TERMINA");

 /* CARCONST */
\'                  	BEGIN(car_cond);
<car_cond>[^\'\n]\'    	{
	BEGIN(INITIAL); 
	yytext[--yyleng] = '\0';
    yylval.lexema = (char*) malloc(yyleng+1);
    if(!yylval.lexema) yyerror("SEM ESPACO DE MEMORIA PARA ALOCACAO");
    strcpy(yylval.lexema,yytext);
	return CARCONST; /* caracter sem escape */
}
<car_cond>\\[^\'\n]\'	{
	BEGIN(INITIAL); 
	yytext[--yyleng] = '\0';
    yylval.lexema = (char*) malloc(yyleng+1);
    if(!yylval.lexema) yyerror("SEM ESPACO DE MEMORIA PARA ALOCACAO");
    strcpy(yylval.lexema,yytext);
	return CARCONST; /* caracter com escape */
}
<car_cond>\n		    yyerror("CARCONST OCUPA MAIS DE UMA LINHA");
<car_cond>\'		    yyerror("CARCONST VAZIO");
<car_cond>[^\'\n]+\'    yyerror("CARCONST COM MAIS DE UM CARACTER");
<car_cond><<EOF>>	    yyerror("CARCONST NAO TERMINA");

{DIGITO}+       {
    yylval.lexema = (char*) malloc(yyleng+1);
    if(!yylval.lexema) yyerror("SEM ESPACO DE MEMORIA PARA ALOCACAO");
    strcpy(yylval.lexema,yytext);
    return INTCONST;
}

<<EOF>>	return(EOF);
[ \t]+ /* espaco inutil */
\n 
.   yyerror("CARACTERE INVALIDO");
%%

int yywrap(){return 1;}