#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = 0;
    nw = 0;
    nc = 0;
    while ((c = getchar()) != EOF) {
        putchar(c);
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT; 
            printf("\n");
        }
        else if (state == OUT) {
            state = IN;
        }
    }
}
