#include <stdio.h>
#include <string.h>
int main()
{
    int n, i, j, found;
    char r[100][20], a[100][20], op[100][20], b[100][20];
    printf("Enter number of instructions: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter instruction %d: ", i + 1);
        scanf("%19s = %19s %19s %19s",
              r[i], a[i], op[i], b[i]);
    }
    printf("\nOptimized Three Address Code:\n");
    for (i = 0; i < n; i++)
    {
        found = 0;
        for (j = 0; j < i; j++)
            if (!strcmp(a[i], a[j]) &&
                !strcmp(op[i], op[j]) &&
                !strcmp(b[i], b[j]))
            {
                printf("%s = %s\n", r[i], r[j]);
                found = 1;
                break;
            }
        if (!found)
            printf("%s = %s %s %s\n", r[i], a[i], op[i], b[i]);
    }

    return 0;
}
