
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define LEN 50

struct Instruction {
    char result[LEN];
    char arg1[LEN];
    char op[LEN];
    char arg2[LEN];
    int valid;
};

struct Instruction code[MAX];

int main(void)
{
    int i, j, n;
    char line[200];

    printf("Enter number of instructions: ");
    scanf("%d", &n);
    getchar();

    if (n < 1 || n > MAX) {
        printf("Invalid number of instructions!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter instruction %d: ", i + 1);
        fgets(line, sizeof(line), stdin);

        if (sscanf(line, "%49s = %49s %49s %49s",
                   code[i].result,
                   code[i].arg1,
                   code[i].op,
                   code[i].arg2) != 4) {
            printf("Invalid instruction!\n");
            return 1;
        }

        code[i].valid = 1;
    }

    printf("\nOptimized Three Address Code:\n");

    for (i = 0; i < n; i++) {
        int found = 0;

        for (j = 0; j < i; j++) {
            if (code[j].valid &&
                strcmp(code[i].arg1, code[j].arg1) == 0 &&
                strcmp(code[i].op, code[j].op) == 0 &&
                strcmp(code[i].arg2, code[j].arg2) == 0) {

                printf("%s = %s\n",
                       code[i].result, code[j].result);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("%s = %s %s %s\n",
                   code[i].result,
                   code[i].arg1,
                   code[i].op,
                   code[i].arg2);
        }
    }

    return 0;
}
