%option noyywrap
%{
#include <stdio.h>
%}
comment "/*"(.|"\n")*"*/"
%%
{comment}  {printf("Comment\n");}
"abc" {strcpy(yytext,"ABC");ECHO;}
. {ECHO;}
%%
int main(){
	printf("Enter the string\n");
	yylex();
	return 0;
}
