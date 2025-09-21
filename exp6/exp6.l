%option noyywrap
%{
#include "exp6.tab.h"
%}
%%
[_a-zA-Z] {return alpha;}
[0-9] {return numeric;}
. {return yytext[0];}
\n {return '\n';}
%%
