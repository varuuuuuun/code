%{
#include<stdio.h>
int yylex(void);
int yyerror(const char *s);
%}
%token IDENTIFIERS NUMBER
%left '+' '-'
%left '*' '/'

%%
expr:
     expr '+' expr
    |expr '-' expr
    |expr '*' expr
    |expr '/' expr
    |'(' expr ')'
    |NUMBER
    |IDENTIFIERS
    ;
%%
int main(){
    printf("Enter the expression\n");
    if(yyparse()==0){
        printf("valid");
        return 0;
    }
}
int yyerror(const char *s){
    printf("Not valid");
    return 0;
}