
#include <stdio.h>
#include <string.h>

#define MAX 50

char lhs[MAX][20], rhs[MAX][50];
int n;

int modified(char *v, int s, int e) {
    for (int i = s + 1; i < e; i++)
        if (!strcmp(lhs[i], v)) return 1;
    return 0;
}

int common(int i, int j) {
    char a[20] = "", b[20] = "";
    char *p = strpbrk(rhs[i], "+-*/");

    if (!p) return 0;
    snprintf(a, sizeof(a), "%.*s", (int)(p-rhs[i]), rhs[i]);
    strcpy(b, p + 1);

    return !strcmp(rhs[i], rhs[j]) &&
           !modified(a, j, i) && !modified(b, j, i);
}

int main() {
    printf("Enter number of three address statements: ");
    scanf("%d", &n);

    printf("Enter statements like t1=a*b\n");
    for (int i = 0; i < n; i++)
        scanf(" %19[^=]=%49s", lhs[i], rhs[i]);

    printf("\nCommon Subexpressions:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (common(i, j)) {
                printf("%s\n", rhs[i]);
                break;
            }

    printf("\nOptimized Three Address Code:\n");
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < i; j++)
            if (common(i, j)) {
                printf("%s=%s\n", lhs[i], lhs[j]);
                found = 1;
                break;
            }
        if (!found) printf("%s=%s\n", lhs[i], rhs[i]);
    }
    return 0;
}
