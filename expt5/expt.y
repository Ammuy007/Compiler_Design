%{
int yyerror();
int yylex();
#include <stdio.h>
%}
%token id num
%left '+' '-'
%left '*' '/'
%left '(' ')'
%%
start : E '\n' {printf("Valid expression\n");return 0;}
E : E '+' E | E '-' E | E '*' E | E '/' E | '(' E ')' | id | num
%%
int main(){
	return yyparse();
}
int yyerror(){
	return printf("Invalid expression\n");
}

