#include <stdio.h>
int main()
{
    int n, i;
    char code[100][20];
    printf("Enter number of instructions: ");
    scanf("%d", &n);
    printf("Enter Intermediate Code:\n");
    for (i = 0; i < n; i++)
        scanf("%19s", code[i]);

    printf("\nTarget Code Generation:\n");
    for (i = 0; i < n; i++)
    {
        char r = code[i][0], a = code[i][2];
        char op = code[i][3], b = code[i][4];
        if (code[i][1] != '=')
        {
            printf("Invalid instruction\n");
            continue;
        }
        printf("MOV AX, %c\n", a);
        switch (op)
        {
            case '+': printf("ADD AX, %c\n", b); break;
            case '-': printf("SUB AX, %c\n", b); break;
            case '*': printf("MUL %c\n", b); break;
            case '/': printf("MOV DX, 0\nDIV %c\n", b); break;
            default: printf("Invalid operator\n"); continue;
        }
        printf("MOV %c, AX\n", r);
    }
    return 0;
}
