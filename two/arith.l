%{
#include "y.tab.h"
%}
%%
[0-9]+  {return NUMBER;}
[a-zA-Z_][a-zA-Z0-9_]*   {return IDENTIFIERS;}
[+\-*/()]               { return yytext[0]; }
[\t]  ;
\n  {return 0;}
.   {return yytext[0];}
%%

int yywrap(){
    return 1;
}