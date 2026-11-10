#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char in[100];
int p=0;

void error(){ printf("Invalid"); exit(0);}

void E();
void Ep();
void T();
void Tp();
void F();

void E(){T();Ep();}
void Ep(){if(in[p]==',') {p++; T();Ep();}}
void T(){F();Tp();}
void Tp(){

}
void F(){
    if(in[p]=='('){
        p++;
        E();
        if(in[p]!=')'){
            error();
        }
        p++;
    }
    else if(in[p]>='a' && in[p]<='z'){
        p++;
    }
    else error();
}

int main(){
    printf("Enter :\n");
    scanf("%99s",in);
    E();
    if(in[p]=='\0') printf("Success\n");
    else printf("rejected\n");
    return 0;
}