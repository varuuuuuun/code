
%{
#include<stdio.h>    
#include<stdlib.h>    


int yylex(void);
void yyerror(const char *s){
    printf("Invalid");
    
}

void zero(){
    printf("div by zero");
    exit(1);
}
%}

%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%%
S : E
{
    printf("Result:%d\n",$1);
}
;

E : E '+' E
{$$=$1+$3;}
|   E '-' E
{$$=$1-$3;}
|   E '*' E
{$$=$1*$3;}
|   E '/' E
{   if(!$3) zero();
    $$=$1/$3;}
|   E '%' E
{   if(!$3) zero();
    $$=$1%$3;}
|NUMBER{
    $$=$1;
}
|'(' E ')'
{ $$ = $2; }   
;
%%

int main(){
    printf("Enter arith expr:\n");
    if(!yyparse()){
        printf("valid");
    }
    return 0;
}