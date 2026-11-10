#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char *kw[]={"void", "int", "float", "char", "if", "else", "while", "return"};
int main(){
    char s[50];
    printf("Enter:\n");
    while(scanf("%s",s)==1){
        int keyw=0;
        for(int i=0;i<8;i++){
            if(strcmp(s,kw[i])==0){
                printf("%s- keyword\n",s);
                keyw=1;
                break;
            }
        }
        if(keyw) continue;
        if(isdigit(s[0])){
            printf("%s-integer\n",s);
        }
        else if(strcmp(s,"=")==0){
            printf("%s-assign\n",s);
        }
        else if(strchr("+-*/%<>",s[0])){
            printf("%s-operator\n",s);
        }
        else if(isalpha(s[0])){
            printf("%s-identifier\n",s);
        }
        else if(strchr("();",s[0])){
            printf("%s-separator\n",s);
        }
        
        
        
    }
    return 0;
}