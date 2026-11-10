#include <stdio.h>
int main(void)
{
    char expr[100], op1, op2, op;
    int i = 0, temp = 1;
    printf("Enter expression (e.g., a+b*c): ");
    scanf("%99s", expr);
    printf("\nThree Address Code:\n");
    while (expr[i] != '\0') {
        if (expr[i] == '*' || expr[i] == '/') {
            op1 = expr[i - 1];
            op = expr[i];
            op2 = expr[i + 1];
            printf("t%d = %c %c %c\n",
                   temp, op1, op, op2);
            expr[i - 1] = '0' + temp;
            for (int j = i; expr[j + 2] != '\0'; j++)
                expr[j] = expr[j + 2];
            expr[i] = '\0';
            temp++;
            i = 0;
        } else {
            i++;
        }
    }
    i = 0;
    while (expr[i] != '\0') {
        if (expr[i] == '+' || expr[i] == '-') {
            op1 = expr[i - 1];
            op = expr[i];
            op2 = expr[i + 1];

            printf("t%d = %c %c %c\n",
                   temp, op1, op, op2);
            temp++;
            break;
        }
        i++;
    }
    return 0;
}
