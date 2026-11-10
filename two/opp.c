#include<stdio.h>
#include<string.h>

char table[4][4]={
    {'x','>','>','>'},
    {'<','>','<','>'},
    {'<','>','>','>'},
    {'<','<','<','a'}
};

int col(char op){
    if(op=='i') return 0;
    else if(op=='+') return 1;
    else if(op=='*') return 2;
    else if(op=='$') return 3;
    return -1;
}

int main(){
    char input[100],stack[100]="$";
    int top=0,i=0;
    printf("Enter an expression:\n");
    scanf("%99s",input);

    strcat(input,"$");

    printf("stack\tinput\taction\n");

    while(1){
        int t=top;
        if(stack[t]=='E') t--;
        if(col(input[i])<0 || col(stack[t])<0 ) {
            printf("invalid symbol\n");
            break;
        }
        char rel=table[col(stack[t])][col(input[i])];
        stack[top+1]='\0';
        printf("%s\t%s\t",stack,input+i);

        if(rel=='a' && top==1){
            printf("accept\n");
            break;
        }
        else if(rel=='<'){
            stack[++top]=input[i++];
            printf("shift\n");
        }
        else if(rel=='>'){
            if(stack[top]=='i'){
                stack[top]='E';
            }
            else if(top>=3 && stack[top]=='E' && stack[top-2]=='E'){
                top-=2;
            }
            else{
                printf("error\n");
                break;
            }
            printf("reduce\n");
        }
        else{
            printf("error from table\n");
            break;
        }
    }
    return 0;
}