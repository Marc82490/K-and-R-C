#include <stdio.h>

int main() {
    int c, nb, nt, nl;

    nb = 0;
    nt = 0;
    nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++nl;
            printf("The number of newlines is: %d\n", nl);
        }

        if (c == ' ') {
            ++nb;
            printf("The number of blanks is: %d\n", nb);
        }

        if (c == '\t') {
            ++nt;
            printf("The number of tabs is: %d\n", nt);
        }
   }

return 0;
}
