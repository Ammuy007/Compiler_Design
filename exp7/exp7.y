%{
#include <stdio.h>
#define YYSTYPE double
int yyerror();
int yylex();
%}
%token FLOAT NL
%left '+' '-'
%left '*' '/'
%right UMINUS
%%
start : E NL {printf("=%f\n",$1);return FLOAT;}
E : E '+' E { $$ = $1 + $3;}
  | E '-' E { $$ = $1 - $3;}
  | E '*' E { $$ = $1 * $3;}
  | E '/' E { $$ = $1 / $3;}
  | '-' E %prec UMINUS {$$ = -$2;}
  | '(' E ')' {$$ = $2; }
  | FLOAT { $$ = $1; }
  ;
%%
int main(){
yyparse();
return 0;
}
int yyerror(){

return printf("Invalid expression\n");
}
