%{
#include <stdio.h>
%}

%%
"int"|"float"|"char"|"if"|"else"|"while"  { printf("%s : Keyword\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*                   { printf("%s : Identifier\n", yytext); }
[0-9]+                                   { printf("%s : Number\n", yytext); }
[+\-*/=<>]                               { printf("%s : Operator\n", yytext); }
[;(),{}]                                 { printf("%s : Special Symbol\n", yytext); }
[ \t\n]+                                 ;
.                                        { printf("%s : Unknown\n", yytext); }
%%

int main(void)
{
    printf("Enter a string:\n");
    yylex();
    return 0;
}

int yywrap(void)
{
    return 1;
}
