%{
#include <stdio.h>
#include <stdlib.h>
typedef double YYSTYPE;  // Use typedef instead of #define
int yyerror();
int yylex();
%}

%token FLOAT NL
%left '+' '-'
%left '*' '/'

%%

start : E NL { printf("=%d\n", $1); return 0; };

E : E '+' E { $$ = $1 + $3; }
  | E '-' E { $$ = $1 - $3; }
  | E '*' E { $$ = $1 * $3; }
  | E '/' E { $$ = $1 / $3; }
  | FLOAT   { $$ = $1; }
  ;
%%

int main(){
    yyparse();
    return 0;
}

int yyerror(){
    printf("Invalid expression\n");
    return 0;
}
