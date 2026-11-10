#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char lhs[20], a[20], b[20], op;
    char var[20][20];
    int val[20], n, k = 0, x, y, r;

    printf("Enter number of statements: ");
    scanf("%d", &n);

    printf("\nEnter statements:\n");

    char code[20][50];

    for (int i = 0; i < n; i++) {
        printf("Statement %d: ", i + 1);
        scanf(" %[^\n]", code[i]);
    }

    printf("\nOptimized Code:\n");

    for (int i = 0; i < n; i++) {
        int count = sscanf(code[i], "%s = %s %c %s",
                           lhs, a, &op, b);

        for (int j = 0; j < k; j++) {
            if (strcmp(a, var[j]) == 0)
                sprintf(a, "%d", val[j]);

            if (count == 4 && strcmp(b, var[j]) == 0)
                sprintf(b, "%d", val[j]);
        }

        if (count == 4) {
            x = atoi(a);
            y = atoi(b);

            switch (op) {
                case '+': r = x + y; break;
                case '-': r = x - y; break;
                case '*': r = x * y; break;
                case '/': r = y ? x / y : 0; break;
                default: r = 0;
            }
        } else {
            r = atoi(a);
        }

        strcpy(var[k], lhs);
        val[k++] = r;

        printf("%s = %d\n", lhs, r);
    }

    return 0;
}