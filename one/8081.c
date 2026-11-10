#include<stdio.h>
#define MAX 100
int main(){
    int n;
    char code[MAX][20];
    printf("Enter the no of ins:\n");
    scanf("%d",&n);
    printf("Enter the ins:\n");
    for(int i=0;i<n;i++)
        scanf("%19s",code[i]);
    printf("target code gen:\n");
    for(int i=0;i<n;i++){
        char r=code[i][0],a=code[i][2],op=code[i][3],b=code[i][4];
        if (code[i][1]!='='){
            printf("Invalid input\n");
            continue;
        }
        printf("MOV AX,%c\n",a);
        switch(op){
            case '+': printf("ADD AX,%c\n",b); break;
            case '-': printf("SUB AX,%c\n",b); break;
            case '*': printf("MUL %c\n",b); break;
            case '/': printf("MOV AX,0\nDIV %c\n",b); break;
            default : printf("Invalid operator\n"); 
        }
        printf("MOV %c,AX\n",r);
    }
    return 0;
}