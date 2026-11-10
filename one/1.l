%{
#include<stdio.h>
%}

%%
"int"|"char"|"float"|"void"|"main"|"if"|"else"|"while" {printf("%s:keywords\n",yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {printf("%s:identifier\n",yytext);}
[0-9]+ {printf("%s:number\n",yytext);}
[+-=;<>\*/] {printf("%s:operator\n",yytext);}
. {printf("%s:Unknown\n",yytext);}
%%

int main(void){
    printf("Enter a string:\n");
    yylex();
    return 0;
}
int yywrap(void)
{
    return 1;
}