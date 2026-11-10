#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int pos=0,n=0,np=0;
char op[50],arg1[50][20],arg2[50][20],res[50][20];
char name[100][20],e[100];

char *E(); char *T(); char *F(); char *P();

void bad(){
    printf("invalid\n");
    exit(0);
}

char *gen(char o,char *a, char *b){
    op[n]=o;
    strcpy(arg1[n],a);
    strcpy(arg2[n],b);
    sprintf(res[n],"t%d",n+1);
    return res[n++];
}

char *E(){
    char *left=T();
    while(e[pos]=='+' || e[pos]=='-'){
        char o=e[pos++];
        left=gen(o,left,T());
    }
    return left;
}
char *T(){
    char *left=F();
    while(e[pos]=='*' || e[pos]=='/'){
        char o=e[pos++];
        left=gen(o,left,F());
    }
    return left;
}
char *F(){
    char *base=P();
    while(e[pos]=='^'){
        pos++;
        base=gen('^',base,F());
    }
    return base;
}

char *P(){
    if(e[pos]=='('){
        char *r=E();
        pos++;
        if(e[pos]!=')'){
            printf("Invalid\n");
            bad();
        }
        pos++;
        return r;
    }
    if(!isalnum(e[pos])) bad();
    int k=0;
    while(isalnum(e[pos])){
        name[np][k++]=e[pos++];
    }
    name[np][k]='\0';
    return name[np++];
}

int main(){
    printf("Enter infix expr:\n");
    scanf("%99s",e);
    E();
    printf("3 address code:\n");
    for(int i=0;i<n;i++){
        printf("%s=%s %c %s\n",res[i],arg1[i],op[i],arg2[i]);
    }
    printf("Quadruple code:\n");
    printf("index\top\targ1\targ2\tres\n");
    for(int i=0;i<n;i++){
        printf("%d\t%c\t%s\t%s\t%s\n",i,op[i],arg1[i],arg2[i],res[i]);
    }

    printf("Triple code\n");
    printf("index\top\targ1\targ2\n");
    for(int i=0;i<n;i++){
        char x[50],y[50];
        strcpy(x,arg1[i]);
        strcpy(y,arg2[i]);
        for(int k=0;k<i;k++){
            if(strcmp(x,res[k])==0) sprintf(x,"(%d)",k);
            if(strcmp(y,res[k])==0) sprintf(y,"(%d)",k);
        }
        printf("%d\t%c\t%s\t%s\n",i,op[i],x,y);
    }
    return 0;

}