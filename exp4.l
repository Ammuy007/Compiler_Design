preprocessor #.*
keyword int|char|double|return|main
string \".*\" 
arith [+\-*/%]
rel "<"|">"|"<="|">="|"=="
ass "+="|"-="|"/="|"*="|"-="
identifier [a-zA-Z_][a-zA-Z_0-9]+
integer [0-9]+
punc [,:]
%%
{string} {printf("\n String:\t%s ",yytext);}
{keyword} {printf("\n Keyword:\t%s ",yytext);}
{preprocessor} {printf("\n Preprocessor directive:\t%s ",yytext);}
{identifier}\( {printf("\n Function:\t%s",yytext);}
\{ {printf("\n begin block");}
\} {printf("\n end block");}
{rel} {printf("\nRelational:%s",yytext);}
{arith} {printf("\nArithmetic:%s",yytext);}
{ass} {printf("\nArithmetic:%s",yytext);}
{identifier}: {printf("\n Label:\t%s ",yytext);}
{identifier} {printf("\n Variable:\t%s ",yytext);}
{integer} {printf("\n Integer Number:\t%s ",yytext);}
\) {printf("\n End of function\t%s ",yytext);}
{punc} {printf("\n Punctuation:\t%s ",yytext);}
%%
int main(int argc,char* argv[]){
	yyin=fopen(argv[1],"r");
	yylex();
	fclose(yyin);
	
return 0;
}
int yywrap(){

return 1;
}
