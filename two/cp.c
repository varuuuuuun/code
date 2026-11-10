#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

int main(){
    char e[200],c;
    int val[256]={0} ,isconst[256]={0},n,v;

    printf("Enter the expression:\n");
    scanf("%199s",e);
    printf("Enter no of constants:\n");
    scanf("%d",&n);
    while(n--){
        printf("Enter variable and its value:\n");
        scanf(" %c %d",&c,&v);
        isconst[(unsigned char)c]=1;
        val[(unsigned char)c]=v;
    }
    printf("the expr z=%s\n",e);
    printf("new expr z=");

    for(char *p=e;*p;p++){
        if(isalpha((unsigned char)*p) && isconst[(unsigned char)*p]){
            printf("%d",val[(unsigned char)*p]);
        }
        else putchar(*p);
    }
    printf("\n");
    return 0;
}