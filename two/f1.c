#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

char prod[20][20], op[20], busy[128],set[128];
int m=0,n;

void add(char c){
    for(int i=0;i<m;i++){
        if(op[i]==c) return;
    }
    op[m++]=c;
}

void show(char type[],char c){
    printf("%s of (%c):{",type,c);
    for(int i=0;i<m;i++){
        printf("%c",op[i]);
    }
    printf("}\n");
}

int first(char c){
    int eps=0;
    if(c<'A' || c>'Z'){
        add(c);
        return 0;
    }
    if(busy[c]) return 0;
    busy[c]=1;

    for(int i=0;i<n;i++){
        if(prod[i][0]!=c) continue;
        int allv=1;
        for(int j=3;prod[i][j]!='\0';j++){
            if(prod[i][j]=='@'){
                eps=1;
                break;
            }
            if(!first(prod[i][j])){
                allv=0;
                break;
            }

        }
        if(allv) eps=1;
    }
    busy[c]=0;
    return eps;
}

void follow(char c){
    if(c<'A' || c>'Z'){
        return;
    }
    if(set[c]) return;
    set[c]=1;

    if(prod[0][0]==c){
        add('$');
    }
    for(int i=0;i<n;i++){
        for(int j=3;prod[i][j]!='\0';j++){
            if(prod[i][j]!=c) continue;
            int alv=1;
            for(int k=j+1;prod[i][k]!='\0';k++){
                if(prod[i][k]=='@'){
                    continue;
                }
                if(!first(prod[i][k])){
                    alv=0;
                    break;
                }
            }
            if(alv) follow(prod[i][0]);
        }
    }
    set[c]=0;
}


int main(){
    printf("Enter no of prod:\n");
    scanf("%d",&n);
    printf("Enter prod:\n");
    for(int i=0;i<n;i++){
        scanf("%s",prod[i]);
    }

    while(1){
        char c;
        printf("Enter a non ter:\n");
        scanf(" %c",&c);

        m=0;
        for(int i=0;i<128;i++){
            busy[i]=0;
        }

        if(first(c)){
            add('@');
        }

        show("first",c);

        m=0;
        for(int i;i<n;i++){
            set[i]=0;
        }
        follow(c);
        show("follow",c);

    }
}