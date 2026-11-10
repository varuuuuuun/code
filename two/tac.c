#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>

char post[200]="",e[100],tac[200]="";
char name[100][20];
int np=0,pos=0,t=1;

char *E();
char *T();
char *F();

void bad(){printf("Invalid expr");exit(1);}

char *gen(char op,char *a,char*b){
    sprintf(name[np],"t%d",t++);
    sprintf(tac + strlen(tac),"%s = %s %s %s",name[np],a,op,b);
    strncat(post,&op,1);
    return name[np++];
}

char *E(){
    char *left=T();
    while(e[pos]=='+' || e[pos]=='-'){
        char op=e[pos++];
        left=gen(op,left,T());
    }
    return left;
}
char *T(){
    char *left=F();
    while(e[pos]=='*' || e[pos]=='/'){
        char op=e[pos++];
        left=gen(op,left,F());
    }
    return left;
}
char *F(){
    
    if(e[pos]=='('){
        pos++;
        char *r=E();
        if(e[pos]!=')'){
            bad();
        }
        pos++;
        return r;

    }
    if(isalnum([unsigned char]e[pos])) bad();

    int k=0;

    while(isalnum([unsigned char]e[pos])){
        name[np][k++]=e[pos++];
    }
    name[np][k]='\0';
    strcat(post,name[np]);
    return name[np++];
}

int main(){
    printf("Enter expression: ");
    scanf("%99s", e);

    char *result = E();

    if (e[pos] != '\0')
        bad();

    printf("\nPostfix: %s\n", post);
    printf("\nThree Address Code:\n%s", tac);

    return 0;
}