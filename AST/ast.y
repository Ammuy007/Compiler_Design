%{
#include "ast.h"
int yyerror();
int yylex();
ASTNODE* root=NULL;
%}
%union{
	int INT;
	ASTNODE* ptr;
}
%token <INT>NUMBER
%token NL
%left '+' '-'
%left '*' '/'
%%
stmt : E NL {root= $<ptr>1; return 0;}
E : E '+' E {$<ptr>$=makenode('+',$<ptr>1,$<ptr>3);}
  | E '-' E {$<ptr>$=makenode('-',$<ptr>1,$<ptr>3);}
  | E '*' E {$<ptr>$=makenode('*',$<ptr>1,$<ptr>3);}
  | E '/' E {$<ptr>$=makenode('/',$<ptr>1,$<ptr>3);}
  | '(' E ')' {$<ptr>$=$<ptr>2;}
  | NUMBER {$<ptr>$=makeleaf($<INT>1);}
  ;
%%
int main(){
	printf("Enter the expression\n");
	yyparse();
	print_ast(root);
	return 0;
}
int yyerror(){

}
