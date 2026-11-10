#include <stdio.h>
#define MAX 100
int main(void)
{
    int n, i;
    char code[MAX][20];
    printf("Enter the number of Intermediate Code statements: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX) {
        printf("Invalid number of statements!\n");
        return 1;
    }
    printf("Enter the set of Intermediate Code:\n");
    for (i = 0; i < n; i++) {
        scanf("%19s", code[i]);
    }
    printf("\nTarget code generation\n");
    for (i = 0; i < n; i++) {
        char result = code[i][0];
        char op1 = code[i][2];
        char op = code[i][3];
        char op2 = code[i][4];
        if (code[i][1] != '=' || code[i][3] == '\0' ||
            code[i][4] == '\0') {
            printf("Invalid instruction: %s\n", code[i]);
            continue;
        }

        switch (op) {
            case '+':
                printf("MOV AX, %c\n", op1);
                printf("ADD AX, %c\n", op2);
                printf("MOV %c, AX\n", result);
                break;

            case '-':
                printf("MOV AX, %c\n", op1);
                printf("SUB AX, %c\n", op2);
                printf("MOV %c, AX\n", result);
                break;

            case '*':
                printf("MOV AX, %c\n", op1);
                printf("MUL %c\n", op2);
                printf("MOV %c, AX\n", result);
                break;

            case '/':
                printf("MOV AX, %c\n", op1);
                printf("MOV DX, 0\n");
                printf("DIV %c\n", op2);
                printf("MOV %c, AX\n", result);
                break;

            default:
                printf("Invalid operator in: %s\n", code[i]);
        }
    }

    return 0;
}
