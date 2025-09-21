%option noyywrap
%{
#include <string.h>
#include <stdio.h>
int l=0,c=0,w=0;
%}
%%
[a-zA-Z]+ {w++;c+=strlen(yytext);}
\n {l++;c++;}
. {c++;}
%%
int main(int argc,char* argv[]){
	yyin=fopen(argv[1],"r");
	yylex();
	fclose(yyin);
	printf("Words=%d\n,Lines=%d\n,Characters=%d\n",w,l,c);
return 0;
}
