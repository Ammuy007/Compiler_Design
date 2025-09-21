%option noyywrap
%{
#include "exp5.tab.h"
%}
%%
[a-zA-Z_][a-zA-Z_0-9]* {return id;}
[0-9]+(\.[0-9]+)? {return num;}
. {return yytext[0];}
\n {return '\n';}
%%
