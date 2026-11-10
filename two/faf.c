#include<stdio.h>
#include<ctype.h>

char p[30][30];
int n,ch,F[26][128],Fo[26][128];

void add(int *s,int c)
{
    if(!s[c]) s[c]=1,ch=1;
}

int firstOf(char *s,int *set)
{
    for(;*s;s++)
    {
        if(*s=='#') continue;
        if(!isupper(*s))
        {
            add(set,*s);
            return 0;
        }
        for(int t=0;t<128;t++)
            if(F[*s-'A'][t] && t!='#') add(set,t);
        if(!F[*s-'A']['#']) return 0;
    }
    return 1;
}

void show(char *name,char c,int *set)
{
    printf("%s(%c) = { ",name,c);
    for(int t=0;t<128;t++)
        if(set[t]) printf("%c ",t);
    printf("}\n");
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",p[i]);

    add(Fo[p[0][0]-'A'],'$');

    do {
        ch=0;
        for(int i=0;i<n;i++)
        {
            int A=p[i][0]-'A';
            char *r=p[i]+2;

            if(firstOf(r,F[A])) add(F[A],'#');

            for(int k=0;r[k];k++)
                if(isupper(r[k]))
                {
                    int B=r[k]-'A';
                    if(firstOf(r+k+1,Fo[B]))
                        for(int t=0;t<128;t++)
                            if(Fo[A][t]) add(Fo[B],t);
                }
        }
    }while(ch);

    printf("FIRST:\n");
    for(int i=0,j;i<n;i++)
    {
        for(j=0;j<i && p[j][0]!=p[i][0];j++);
        if(j<i) continue;
        show("FIRST",p[i][0],F[p[i][0]-'A']);
    }

    printf("\nFOLLOW:\n");
    for(int i=0,j;i<n;i++)
    {
        for(j=0;j<i && p[j][0]!=p[i][0];j++);
        if(j<i) continue;
        show("FOLLOW",p[i][0],Fo[p[i][0]-'A']);
    }
}