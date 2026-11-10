#include <stdio.h>
int tr[20][20][20], cl[20][20];
char a[20];
int n, m, t;
void closure(int s, int x)
{
    int i, j;
    cl[x][s] = 1;

    for (i = 0; i < m; i++)
        if (a[i] == 'e')
            for (j = 1; j <= n; j++)
                if (tr[s][i][j] && !cl[x][j])
                    closure(j, x);
}
int main()
{
    int i, j, r, s;
    char c;
    printf("Enter the number of alphabets --> ");
    scanf("%d", &m);
    printf("Enter alphabets:\n");
    for (i = 0; i < m; i++)
        scanf(" %c", &a[i]);
    printf("Enter the number of states --> ");
    scanf("%d", &n);
    printf("Enter no of transition --> ");
    scanf("%d", &t);
    printf("Enter transition (state alphabet state):\n");
    for (i = 0; i < t; i++)
    {
        scanf("%d %c %d", &r, &c, &s);
        for (j = 0; j < m; j++)
            if (a[j] == c)
                tr[r][j][s] = 1;
    }
    printf("\n-----E-closure of states-----\n");
    for (i = 1; i <= n; i++)
    {
        closure(i, i);
        printf("\nE-closure(q%d): {", i);
        for (j = 1; j <= n; j++)
            if (cl[i][j])
                printf("q%d,", j);
        printf("}\n");
    }
    return 0;
}
