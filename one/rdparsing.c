
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char input[100];
int i = 0;

void S(void);
void Sprime(void);
void A(void);
void Aprime(void);
void B(void);

void S(void)
{
    A();
    Sprime();
}

void Sprime(void)
{
    if (input[i] == ',')
    {
        i++;
        A();
        Sprime();
    }
}

void A(void)
{
    B();
    Aprime();
}

void Aprime(void)
{
    if (input[i] == ',')
    {
        i++;
        B();
        Aprime();
    }
}

void B(void)
{
    if (input[i] == '(')
    {
        i++;
        S();

        if (input[i] == ')')
            i++;
        else
        {
            printf("Rejected\n");
            exit(0);
        }
    }
    else if (isalpha((unsigned char)input[i]))
    {
        while (isalnum((unsigned char)input[i]) ||
               input[i] == '_')
        {
            i++;
        }
    }
    else
    {
        printf("Rejected\n");
        exit(0);
    }
}

int main(void)
{
    printf("Enter the input string: ");

    if (scanf("%99s", input) != 1)
        return 1;

    S();

    if (input[i] == '\0')
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}
