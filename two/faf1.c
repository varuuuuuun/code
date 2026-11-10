#include<stdio.h>
#include<ctype.h>
char p[30][30];
int n,ch,F[26][128],Fo[26][128];
void add(int s[],int c){ 
    if(!s[c]) s[c]=1,ch=1; }
int first(char *s,int set[]){
    for(;*s;s++){
        if(*s=='#') continue;
        if(!isupper(*s)) { add(set,*s); return 0; }
        for(int j=0;j<128;j++)
            if(j!='#' && F[*s-'A'][j]) add(set,j);
        if(!F[*s-'A']['#']) return 0;
    }
    return 1;
}
int main(){
    int A,B,seen[26]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",p[i]);
    add(Fo[p[0][0]-'A'],'$');
    do {
        ch=0;
        for(int i=0;i<n;i++){
            A=p[i][0]-'A';
            char *r=p[i]+2;
            if(first(r,F[A])) add(F[A],'#');
            for(int k=0;r[k];k++) if(isupper(r[k]))
            {
                B=r[k]-'A';
                if(first(r+k+1,Fo[B]))
                    for(int j=0;j<128;j++)
                        if(Fo[A][j]) add(Fo[B],j);
            }
        }
    }while(ch);
    printf("FIRST:\n");
    for(int i=0;i<n;i++){
        A=p[i][0]-'A';
        if(!seen[A]){
            seen[A]=1;
            printf("%c = { ",p[i][0]);
            for(int j=0;j<128;j++) if(F[A][j]) printf("%c ",j);
            printf("}\n");
        }
    }
    for(int i=0;i<26;i++) seen[i]=0;
    printf("FOLLOW:\n");
    for(int i=0;i<n;i++){
        A=p[i][0]-'A';
        if(!seen[A]){
            seen[A]=1;
            printf("%c = { ",p[i][0]);
            for(int j=0;j<128;j++) if(Fo[A][j]) printf("%c ",j);
            printf("}\n");
        }
    }
    return 0;
}