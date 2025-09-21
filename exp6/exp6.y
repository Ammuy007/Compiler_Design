%{
#include <stdio.h>
int yyerror();
int yylex();
%}
%token alpha numeric
%%
start : S '\n' {printf("Valid\n"); return 0;}
S : alpha A
A : alpha A | numeric A | ;
%%
int main(){

return yyparse();
}
int yyerror(){
	return printf("Invalid\n");
}
