#include <stdio.h>
int main()
{
    int n, e, i, j, k;
    int closure[20][20] = {0};
    int from, to;
    printf("Enter number of states: ");
    scanf("%d", &n);
    printf("Enter number of epsilon transitions: ");
    scanf("%d", &e);
    for (i = 0; i < n; i++)
        closure[i][i] = 1;
    printf("Enter epsilon transitions (from to):\n");
    for (i = 0; i < e; i++)
    {
        scanf("%d %d", &from, &to);
        closure[from][to] = 1;
    }

    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                closure[i][j] =
                    closure[i][j] ||
                    (closure[i][k] && closure[k][j]);
    printf("\nEpsilon Closure of all states:\n");
    for (i = 0; i < n; i++)
    {
        printf("E-Closure(q%d) = { ", i);

        for (j = 0; j < n; j++)
            if (closure[i][j])
                printf("q%d ", j);
        printf("}\n");
    }
    return 0;
}
