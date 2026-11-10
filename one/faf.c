
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n, m = 0;
char a[10][10], f[20];

void first(char c);
void follow(char c);

void add(char c)
{
    int k;

    for (k = 0; k < m; k++)
        if (f[k] == c)
            return;

    f[m++] = c;
}

void first(char c)
{
    int k;

    if (!isupper((unsigned char)c))
    {
        add(c);
        return;
    }

    for (k = 0; k < n; k++)
    {
        if (a[k][0] == c)
        {
            if (a[k][2] == '$')
                add('$');
            else if (!isupper((unsigned char)a[k][2]))
                add(a[k][2]);
            else
                first(a[k][2]);
        }
    }
}

void follow(char c)
{
    int i, j;

    if (a[0][0] == c)
        add('#');

    for (i = 0; i < n; i++)
    {
        for (j = 2; a[i][j] != '\0'; j++)
        {
            if (a[i][j] == c)
            {
                if (a[i][j + 1] != '\0')
                {
                    first(a[i][j + 1]);
                }

                if (a[i][j + 1] == '\0' && c != a[i][0])
                {
                    follow(a[i][0]);
                }
            }
        }
    }
}

int main(void)
{
    int i, k, exists;
    char c;

    printf("Enter the number of productions: ");
    scanf("%d", &n);

    printf("Enter the productions (use $ for epsilon):\n");

    for (i = 0; i < n; i++)
        scanf("%9s", a[i]);

    printf("\nFIRST and FOLLOW of all non-terminals:\n\n");

    for (k = 0; k < n; k++)
    {
        c = a[k][0];
        exists = 0;

        for (i = 0; i < k; i++)
        {
            if (a[i][0] == c)
            {
                exists = 1;
                break;
            }
        }

        if (exists)
            continue;

        m = 0;
        first(c);

        printf("FIRST(%c) = { ", c);
        for (i = 0; i < m; i++)
            printf("%c ", f[i]);
        printf("}\n");

        m = 0;
        follow(c);

        printf("FOLLOW(%c) = { ", c);
        for (i = 0; i < m; i++)
            printf("%c ", f[i]);
        printf("}\n\n");
    }

    return 0;
}
