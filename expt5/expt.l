%option noyywrap
%{
#include "expt.tab.h"
%}
%%
[a-z_A-Z][a-zA-Z_0-9]* {return id;}
[0-9]+(\.[0-9]+)? {return num;}
. {return yytext[0];}
\n {return '\n';}
%%
