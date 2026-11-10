#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

char prod[20][20],busy[128],op[20];
int m=0,n;

void add(char c){
    for(int i=0;i<m;i++){
        if(op[i]==c) return;
    }
    op[m++]=c;
}

void show(char type[],char c){
    printf("%s of (%c)={",type,c);
    for(int i=0;i<m;i++){
        printf("%c",op[i]);
    }
    printf("}\n");
}


int first(char c){
    int eps=0;
    if(c<'A' || c>'Z'){
        add(c); return 0;
    }
    if(busy[c]) return 0;
    busy[c]=1;
    for(int i=0;i<n;i++){
        int allvanish=1;
        if(prod[i][0]!=c) continue;
        for(int j=3;prod[i][j]!='\0';j++){
            if(prod[i][j]=='@'){
                eps=1;
                break;
            }
            if(!first(prod[i][j])){
                allvanish=0;
                break;
            }
        }
        if(allvanish){
            eps=1;
        }
        
    }



    busy[c]=0;
    return eps;
}


int main(){
    printf("Enter no of produvtion:\n");
    scanf("%d",&n);
    printf("eneter prod:\n");
    for(int i=0;i<n;i++){
        scanf("%s",prod[i]);
    }
    while(1){
        //non_terminal
        char c;
        printf("Enter non terminal\n");
        scanf(" %c",&c);

        //reset
        m=0;
        for(int i=0;i<128;i++){
            busy[i]=0;
        }

        //call fisrt

        if(first(c)){
            add('@');
        }

        //print

        show("first",c);
    }
}
