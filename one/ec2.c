#include<stdio.h>
int n,m,t;
int tr[20][20][20],cl[20][20];
char a[20];
void closure(int s,int x){
    cl[x][s]=1;
    for(int i=0;i<m;i++){
        if(a[i]=='e')
            for(int j=1;j<=n;j++){
                if(tr[s][i][j] && !cl[x][j])
                    closure(j,x);
            }
    }
}
int main(){
    int r,s;
    char c;
    printf("Enter the number of alphabets\n");
    scanf("%d",&m);
    printf("Enter the alphabets:\n");
    for(int i=0;i<m;i++){
        scanf(" %c",&a[i]);
    }
    printf("Enter the number of states\n");
    scanf("%d",&n);
    printf("Enter the number of transitions\n");
    scanf("%d",&t);
    printf("Enter the transitions:\n");
    for(int i=0;i<t;i++){
        scanf("%d %c %d",&r,&c,&s);
        for(int j=0;j<m;j++){
            if (a[j]==c){
                tr[r][j][s]=1;
            }
        }
    }
    printf("the e-closure is:\n");
    for(int i=1;i<=n;i++){
        printf("e-cl(q%d):{",i);
        closure(i,i);
        for(int j=1;j<=n;j++){
            if(cl[i][j]){
                printf("q %d,",j);
            }
        }
        printf("}\n");
    }
}