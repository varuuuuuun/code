#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char s[100], tok[20];
    char kw[][10] = {"int", "float", "char", "if", "else", "while"};
    int i = 0, j, k, found;
    printf("Enter a string: ");
    fgets(s, 100, stdin);
    while (s[i])
    {
        if (isspace(s[i])) i++;
        else if (isalpha(s[i]) || s[i] == '_')
        {
            j = 0;
            while (isalnum(s[i]) || s[i] == '_')
                tok[j++] = s[i++];
            tok[j] = '\0';
            found = 0;
            for (k = 0; k < 6; k++)
                if (!strcmp(tok, kw[k])) found = 1;
            printf("%s : %s\n", tok, found ? "Keyword" : "Identifier");
        }
        else if (isdigit(s[i]))
        {
            j = 0;
            while (isdigit(s[i])) tok[j++] = s[i++];
            tok[j] = '\0';
            printf("%s : Number\n", tok);
        }
        else
        {
            printf("%c : %s\n", s[i],
                   strchr("+-*/=<>", s[i]) ? "Operator" : "Special Symbol");
            i++;
        }
    }
    return 0;
}
