
#include <stdio.h>
#include <string.h>

char input[50], stack[50];
int top = 0;

char table[4][4] = {
    {'>', '>', '>', '>'},
    {'<', '>', '<', '>'},
    {'<', '>', '>', '>'},
    {'<', '<', '<', '='}
};

int pos(char c) {
    if (c == 'i') return 0;
    if (c == '+') return 1;
    if (c == '*') return 2;
    if (c == '$') return 3;
    return -1;
}

void printStack() {
    for (int i = 0; i <= top; i++)
        printf("%c", stack[i]);
}

int main() {
    int i = 0, k, p, q;
    char rel;

    printf("Enter expression: ");
    scanf("%49s", input);
    strcat(input, "$");
    stack[0] = '$';

    printf("\nStack\t\tInput\t\tAction\n");
    printf("------------------------------------------\n");

    while (1) {
        if (top == 1 && stack[1] == 'E' && input[i] == '$') {
            printStack();
            printf("\t$\t\tACCEPT\nValid Expression\n");
            break;
        }

        k = top;
        while (k >= 0 && pos(stack[k]) == -1)
            k--;

        p = (k >= 0) ? pos(stack[k]) : -1;
        q = pos(input[i]);

        if (p == -1 || q == -1) {
            printf("ERROR\nInvalid Expression\n");
            break;
        }

        rel = table[p][q];
        printStack();
        printf("\t%s\t\t", input + i);

        if (rel == '<' || rel == '=') {
            stack[++top] = input[i++];
            printf("SHIFT\n");
        } else if (rel == '>') {
            if (stack[top] == 'i') {
                stack[top] = 'E';
            } else if (top >= 2 && stack[top] == 'E' &&
                       (stack[top-1] == '+' || stack[top-1] == '*') &&
                       stack[top-2] == 'E') {
                top -= 2;
                stack[top] = 'E';
            } else {
                printf("ERROR\nInvalid Expression\n");
                break;
            }
            printf("REDUCE\n");
        } else {
            printf("ERROR\nInvalid Expression\n");
            break;
        }
    }

    return 0;
}
