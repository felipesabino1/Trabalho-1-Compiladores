%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokens.h"
#include "tipos.h"
char msg[500];
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
	if(!yylval.lexema){
		strcpy(msg,"SEM ESPACO DE MEMORIA PARA ALOCACAO");
		yyerror(msg);
	}
	strcpy(yylval.lexema,yytext);
	return IDENTIFICADOR;
}
 /* comentario */
"/*"	BEGIN(comentario_cond);
<comentario_cond>[^*\n]	/* consome o comentario */
<comentario_cond>\n 
<comentario_cond>"*"+[^*/\n]*   /* consome * que nao tem / em sequencia */
<comentario_cond><<EOF>>	{
	strcpy(msg,"COMENTARIO NAO TERMINA");
	yyerror(msg);
}
<comentario_cond>"*"+"/"        BEGIN(INITIAL);


 /* CADEIACARACTERES */
\"			BEGIN(cadeia_cond); 
<cadeia_cond>[^"\n]*\"	{
	BEGIN(INITIAL); 
	yytext[--yyleng] = '\0'; /* remover a ultima \" */
    yylval.lexema = (char*) malloc(yyleng+1);
    if(!yylval.lexema){
        strcpy(msg,"SEM ESPACO DE MEMORIA PARA ALOCACAO");
        yyerror(msg);
    }
    strcpy(yylval.lexema,yytext);
	return CADEIACARACTERES;
}
<cadeia_cond>[^"\n]*(\n)+	{
	strcpy(msg, "CADEIA DE CARACTERES OCUPA MAIS DE UMA LINHA");
	yyerror(msg);
}
<cadeia_cond><<EOF>>	{
	strcpy(msg,"CADEIA DE CARACTERES NAO TERMINA");
	yyerror(msg);
}

 /* CARCONST */
\'                  	BEGIN(car_cond);
<car_cond>[^\'\n]\'    	{
	BEGIN(INITIAL); 
	yytext[--yyleng] = '\0';
    yylval.lexema = (char*) malloc(yyleng+1);
    if(!yylval.lexema){
        strcpy(msg,"SEM ESPACO DE MEMORIA PARA ALOCACAO");
        yyerror(msg);
    }
    strcpy(yylval.lexema,yytext);
	return CARCONST; /* caracter sem escape */
}
<car_cond>\\[^\'\n]\'	{
	BEGIN(INITIAL); 
	yytext[--yyleng] = '\0';
    yylval.lexema = (char*) malloc(yyleng+1);
    if(!yylval.lexema){
        strcpy(msg,"SEM ESPACO DE MEMORIA PARA ALOCACAO");
        yyerror(msg);
    }
    strcpy(yylval.lexema,yytext);
	return CARCONST; /* caracter com escape */
}
<car_cond>\n		{
	strcpy(msg,"CARCONST OCUPA MAIS DE UMA LINHA");
	yyerror(msg);
}
<car_cond>\'		{
	strcpy(msg,"CARCONST VAZIO");
	yyerror(msg);
}
<car_cond>[^\'\n]+\'	{
	strcpy(msg,"CARCONST COM MAIS DE UM CARACTER");
	yyerror(msg);
}
<car_cond><<EOF>>	{
	strcpy(msg,"CARCONST NAO TERMINA");
	yyerror(msg);
}

{DIGITO}+       {
    yylval.lexema = (char*) malloc(yyleng+1);
    if(!yylval.lexema){
        strcpy(msg,"SEM ESPACO DE MEMORIA PARA ALOCACAO");
        yyerror(msg);
    }
    strcpy(yylval.lexema,yytext);
    return INTCONST;
}

<<EOF>>	return(EOF);
[ \t]+ /* espaco inutil */
\n 
. {
    strcpy(msg,"CARACTERE INVALIDO");
    yyerror(msg);
}

%%

int yywrap(){return 1;}