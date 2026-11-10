#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct {char res[50],a[50],op[50],b[50];}c[50];
int expr(int i,int j){
    return(strcmp(c[i].a,c[j].a)==0 && strcmp(c[i].op,c[j].op)==0 && strcmp(c[i].b,c[j].b)==0 );
}

int changed(int j,int i){
    for(int k=j+1;k<i;k++){
        if(strcmp(c[k].res,c[j].res)==0 || strcmp(c[k].a,c[j].a)==0 || strcmp(c[k].b,c[j].b)==0){
            return 1;
        }
    }
    return 0;
}

int main(){
    int n;
    printf("Enter no of expr:\n");
    scanf("%d",&n);
    printf("Enter exprs:");
    for(int i=0;i<n;i++){
        if(scanf("%s = %s %s %s",c[i].res,c[i].a,c[i].op,c[i].b)!=4){
            printf("Invalid\n");
            return 1;
        }
    }
    printf("comsub\n");
    for(int i=0;i<n;i++){
        int f=-1;
        for(int j=0;j<i;j++){
            if(expr(i,j) && !changed(j,i)){f=j; break;}
        }
        if(f>=0){printf("%s = %s\n",c[i].res,c[f].res);}
        else{printf("%s = %s %s %s\n",c[i].res,c[i].a,c[i].op,c[i].b);}
    }
    return 0;
}