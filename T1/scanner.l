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
	if(!yylval.lexema) yyerror("sem espaco de memoria para alocacao");
	strcpy(yylval.lexema,yytext);
	return IDENTIFICADOR;
}
 /* comentario */
"/*"	BEGIN(comentario_cond);
<comentario_cond>[^*\n]	/* consome o comentario */
<comentario_cond>\n 
<comentario_cond>"*"+[^*/\n]*   /* consome * que nao tem / em sequencia */
<comentario_cond><<EOF>>	    yyerror("comentario nao termina");

<comentario_cond>"*"+"/"        BEGIN(INITIAL);


 /* CADEIACARACTERES */
\"			BEGIN(cadeia_cond); 
<cadeia_cond>[^"\n]*\"	{
	BEGIN(INITIAL); 
	yytext[--yyleng] = '\0'; /* remover a ultima \" */
    yylval.lexema = (char*) malloc(yyleng+1);
    if(!yylval.lexema) yyerror("sem espaco de memoria para alocacao");
    strcpy(yylval.lexema,yytext);
	return CADEIACARACTERES;
}
<cadeia_cond>[^"\n]*(\n)+	yyerror("cadeia de caracteres ocupa mais de uma linha");
<cadeia_cond><<EOF>>	    yyerror("cadeia de caracteres nao termina");

 /* CARCONST */
\'                  	BEGIN(car_cond);
<car_cond>[^\'\n]\'    	{
	BEGIN(INITIAL); 
	yytext[--yyleng] = '\0';
    yylval.lexema = (char*) malloc(yyleng+1);
    if(!yylval.lexema) yyerror("sem espaco de memoria para alocacao");
    strcpy(yylval.lexema,yytext);
	return CARCONST; /* caracter sem escape */
}
<car_cond>\\[^\'\n]\'	{
	BEGIN(INITIAL); 
	yytext[--yyleng] = '\0';
    yylval.lexema = (char*) malloc(yyleng+1);
    if(!yylval.lexema) yyerror("sem espaco de memoria para alocacao");
    strcpy(yylval.lexema,yytext);
	return CARCONST; /* caracter com escape */
}
<car_cond>\n		    yyerror("carconst ocupa mais de uma linha");
<car_cond>\'		    yyerror("carconst vazio");
<car_cond>[^\'\n]+\'    yyerror("carconst com mais de um caracter");
<car_cond><<EOF>>	    yyerror("carconst nao termina");

{DIGITO}+       {
    yylval.lexema = (char*) malloc(yyleng+1);
    if(!yylval.lexema) yyerror("sem espaco de memoria para alocacao");
    strcpy(yylval.lexema,yytext);
    return INTCONST;
}

<<EOF>>	return(EOF);
[ \t]+ /* espaco inutil */
\n 
.   yyerror("caracter invalido");
%%

int yywrap(){return 1;}