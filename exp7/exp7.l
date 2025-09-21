%option noyywrap
%{
#include <stdlib.h>
#include "exp72.tab.h"
%}
%%
[0-9]+\.[0-9]+ {yylval=atof(yytext);return FLOAT;}
[0-9]+ {yylval=atof(yytext);return FLOAT;}
\n {return NL;}
. {return yytext[0];}
%%
