#include <stdio.h>
#include <ctype.h>
char prod[20][20];
int n, changed, first[26][128], follow[26][128];
void add(int set[], int c) {
    if (!set[c]) set[c] = 1, changed = 1;
}
int firstOf(char *s, int set[]) {
    for (int k = 0; s[k]; k++) {
        char c = s[k];
        if (!isupper(c)) {
            if (c == '#') return 1;
            add(set, c);
            return 0;
        }
        for (int t = 0; t < 128; t++)
            if (first[c-'A'][t] && t != '#') add(set, t);
        if (!first[c-'A']['#']) return 0;
    }
    return 1;
}
void print(char *name, char c, int set[]) {
    printf("%s(%c) = {", name, c);
    for (int t = 0; t < 128; t++)
        if (set[t]) printf("%c ", t);
    printf("}\n");
}
int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter productions:\n");
    for (int i = 0; i < n; i++) scanf("%s", prod[i]);

    add(follow[prod[0][0]-'A'], '$');

    do {
        changed = 0;
        for (int i = 0; i < n; i++) {
            int A = prod[i][0]-'A';
            char *rhs = prod[i]+2;

            if (firstOf(rhs, first[A])) add(first[A], '#');

            for (int k = 0; rhs[k]; k++) {
                if (!isupper(rhs[k])) continue;
                int B = rhs[k]-'A';

                if (firstOf(rhs+k+1, follow[B]))
                    for (int t = 0; t < 128; t++)
                        if (follow[A][t]) add(follow[B], t);
            }
        }
    } while (changed);

    printf("\nFIRST:\n");
    for (int i = 0; i < n; i++) {
        int seen = 0;
        for (int j = 0; j < i; j++)
            if (prod[j][0] == prod[i][0]) seen = 1;
        if (!seen) print("FIRST", prod[i][0], first[prod[i][0]-'A']);
    }

    printf("\nFOLLOW:\n");
    for (int i = 0; i < n; i++) {
        int seen = 0;
        for (int j = 0; j < i; j++)
            if (prod[j][0] == prod[i][0]) seen = 1;
        if (!seen) print("FOLLOW", prod[i][0], follow[prod[i][0]-'A']);
    }

    return 0;
}