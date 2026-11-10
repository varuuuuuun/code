
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *kw[] = {"int","char","float","double","if","else","for","while",
"do","return","void","break","continue","switch","case","default",
"auto","const","enum","extern","goto","long","register","short",
"signed","sizeof","static","struct","typedef","union","unsigned",
"volatile","inline","restrict","_Bool","_Complex","_Imaginary"};

char names[100][100];
int n = 0;

int keyword(char *s) {
    for (int i = 0; i < sizeof(kw)/sizeof(kw[0]); i++)
        if (!strcmp(s, kw[i])) return 1;
    return 0;
}

int id(char *s) {
    for (int i = 0; i < n; i++)
        if (!strcmp(s, names[i])) return i + 8;
    strcpy(names[n], s);
    return ++n + 7;
}

int main() {
    char s[1000], t[100];
    int i, j, comment = 0;

    while (fgets(s, sizeof(s), stdin))
        for (i = 0; s[i]; ) {
            if (comment) {
                if (s[i]=='*' && s[i+1]=='/')
                    comment=0, i+=2;
                else i++;
            }
            else if (isspace(s[i])) i++;
            else if (s[i]=='/' && s[i+1]=='/') break;
            else if (s[i]=='/' && s[i+1]=='*')
                comment=1, i+=2;
            else if (isalpha(s[i]) || s[i]=='_') {
                for (j=0; isalnum(s[i]) || s[i]=='_'; )
                    if (j<99) t[j++]=s[i++];
                    else i++;
                t[j]=0;
                if (keyword(t)) printf("%s - keyword\n",t);
                else printf("%s - identifier, %d\n",t,id(t));
            }
            else if (isdigit(s[i])) {
                for (j=0; isdigit(s[i]); ) t[j++]=s[i++];
                if (s[i]=='.' && isdigit(s[i+1])) {
                    t[j++]=s[i++];
                    while (isdigit(s[i])) t[j++]=s[i++];
                }
                t[j]=0;
                printf("%s - Number\n",t);
            }
            else if (s[i]=='=')
                printf("= - assign\n"), i++;
            else if (strchr("+-*/%<>!&|^",s[i]))
                printf("%c - operator\n",s[i++]);
            else if (s[i]=='"' || s[i]=='\'') {
                char q=s[i++];
                while (s[i] && s[i]!=q) {
                    if (s[i]=='\\' && s[i+1]) i++;
                    i++;
                }
                if (s[i]) i++;
            }
            else i++;
        }
    return 0;
}
