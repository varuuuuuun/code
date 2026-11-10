
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[50];
int i = 0, error = 0;

void E();
void T();
void F();

void E() {
    T();
    while (input[i] == '+') {
        i++;
        T();
    }
}

void T() {
    F();
    while (input[i] == '*') {
        i++;
        F();
    }
}

void F() {
    if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')') i++;
        else error = 1;
    }
    else if (input[i] == 'i' && input[i+1] == 'd')
        i += 2;
    else
        error = 1;
}

int main() {
    printf("Enter expression: ");
    scanf("%49s", input);

    E();

    if (i == strlen(input) && !error)
        printf("Valid Expression\n");
    else
        printf("Invalid Expression\n");

    return 0;
}
