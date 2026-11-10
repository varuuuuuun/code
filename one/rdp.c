
#include <stdio.h>
#include <ctype.h>

char s[50];
int i = 0, err = 0;

void E();
void T();
void F();

void E() {
    T();
    while (s[i] == '+') i++, T();
}

void T() {
    F();
    while (s[i] == '*') i++, F();
}

void F() {
    if (s[i] == '(') {
        i++; E();
        if (s[i] == ')') i++;
        else err = 1;
    }
    else if (isalnum((unsigned char)s[i])) i++;
    else err = 1;
}

int main() {
    printf("Enter expression: ");
    scanf("%49s", s);
    E();
    if (!err && s[i] == '\0') {
        printf("Valid Expression\n");
    } else {
        printf("Invalid Expression\n");
    }
    return 0;
}
