#include<stdio.h>
#include<string.h>

struct {char res[20],a[20],op[20],b[20];}c[50];

int sameexp(int i,int j){
    return (strcmp(c[i].a,c[j].a)==0 && strcmp(c[i].op,c[j].op)==0 && strcmp(c[i].b,c[j].b)==0);
}
int changed(int j,int i){
    for(int k=j+1;k<i;k++){
        if(strcmp(c[k].res,c[j].a)==0 || strcmp(c[k].res,c[j].b)==0 || strcmp(c[k].res,c[j].res)==0){
            return 1;
        }
    
    }
    return 0;
}

int main(){
    int n;
    printf("Enter the no of exp:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        if(scanf("%s = %s %s %s",c[i].res,c[i].a,c[i].op,c[i].b)!=4){
            printf("invalid\n");
            return 1;
        }
    }
    printf("opt expr:\n");
    
    for(int i=0;i<n;i++){
        int f=-1;
        for(int j=0;j<i;j++){
            if(sameexp(i,j) && !changed(j,i)){f=j; break;}
        }
        if(f>=0){printf("%s = %s\n",c[i].res,c[f].res);}
        else{
            printf("%s = %s %s %s\n",c[i].res,c[i].a,c[i].op,c[i].b);
        }
    }
    return 0;

}