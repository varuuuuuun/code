#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char expr[100], propagated[200], vars[26] = {0};
    int value[26] = {0}, constant[26] = {0};
    int i, j = 0, n;

    printf("Enter expression: ");
    if (scanf("%99s", expr) != 1) return 1;

    printf("Enter the values of variables:\n");
    for (i = 0; expr[i]; i++) {
        if (expr[i] >= 'a' && expr[i] <= 'z') {
            int k = expr[i] - 'a';
            if (!vars[k]) {
                printf("Enter value for %c: ", expr[i]);
                if (scanf("%d", &value[k]) != 1) return 1;
                vars[k] = 1;
            }
        }
    }

    printf("Enter number of constant variables: ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 26) return 1;
    printf("Enter the constant variable names:\n");
    for (i = 0; i < n; i++) {
        char ch;
        scanf(" %c", &ch);
        if (ch >= 'a' && ch <= 'z')
            constant[ch - 'a'] = 1;
    }

    for (i = 0; expr[i]; i++) {
        if (expr[i] >= 'a' && expr[i] <= 'z' && constant[expr[i] - 'a']) {
            j += sprintf(propagated + j, "%d", value[expr[i] - 'a']);
        } else {
            propagated[j++] = expr[i];
        }
    }
    propagated[j] = '\0';

    printf("\nOriginal Expression : z = %s\n", expr);
    printf("After Propagation : z = %s\n", propagated);
    printf("\nTarget Code\n");

    {
        char *p = propagated;
        char left[50], right[50], op;
        int k = 0;
        while (p[k] && p[k] != '+' && p[k] != '-' &&
               p[k] != '*' && p[k] != '/')
            k++;
        if (p[k]) {
            op = p[k];
            snprintf(left, sizeof(left), "%.*s", k, p);
            snprintf(right, sizeof(right), "%s", p + k + 1);
            printf("z = %s %c %s\n", left, op, right);
        } else {
            printf("z = %s\n", propagated);
        }
    }

    return 0;
}