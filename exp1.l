%option noyywrap
%{
#include <stdio.h>
#include <string.h>

int v=0;
int c=0;
char matched[100]="";
%}
%%
[aeiouAEIOU] {v++;strcat(matched,yytext);}
[a-zA-Z] {c++;printf("Consonant:");ECHO;printf("\n");}
\n {return 0;}
. {}
%%
int main(){
	printf("Enter the string\n");
	yylex();
	printf("matched:%s\n",matched);
	printf("The number of vowels and consonants are %d and %d\n",v,c);
return 0;
}
