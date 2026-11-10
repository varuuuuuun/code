#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char in[100];
int p=0;

void E();
void Ep();
void T();
void Tp();
void F();

void error(){printf("Invalid\n"); exit(0);}

void E(){T(); Ep(); }
void Ep(){if(in[p]=='+'){p++; T(); Ep();} }
void T(){F(); Tp(); }
void Tp(){if(in[p]=='*'){p++; F(); Tp();} }
void F(){
    if(in[p]=='('){
        p++;
        E();
        if(in[p]!=')'){
            error();
        }
        p++;
    }
    else if(in[p]=='i' && in[p+1]=='d'){p+=2;}
    else error();
}

int main(){
    printf("Enter the expr:\n");
    scanf("%99s",in);
    E();
    if(in[p]=='\0') printf("Successful\n");
    else printf("Rejected\n");
    return 0;
}