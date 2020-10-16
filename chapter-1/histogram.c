#include <stdio.h>

int main() {
    /* count length of word */
    int c, wl, max;
    int nchar[15] = { 0 };

    wl = 0;
    while ((c = getchar()) != EOF) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c<= 'z')) {
            ++wl;
        }
/*        else if (c == ' ' || c == '\n' || c == '\t') {  */
        else {
            ++nchar[wl];
            wl = 0;
        } 
    }

    /* print the array of word lengths */
    for (int i = 0; i < 15; ++i) {
        printf(" %d", nchar[i]);
    }

    max = 10;
    /* print histogram */
    while (max >= 0) {
        for (int i = 0; i < 15; ++i) {
            if (nchar[i] >= max) {
                printf("|");
                --nchar[i];
            }
            else {
                printf(" ");
            }
        }         
        printf("\n");
        --max;
    }
}

