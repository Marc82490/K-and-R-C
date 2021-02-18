#include <stdio.h>

unsigned rightrot(unsigned x, int n) {
    unsigned y = 0;
    int i;

    for (i = 0; i < n; i++) {
        /* save rightmost value of x */
        y = x & 1;

        /* shift y to leftmost bit */
        y = y << 7;

        /* shift x right by one */
        x = x >> 1;

        /* set leftmost bit to saved value */
        x = x | y;
    }
    
    return x;
}

int main() {
    unsigned x = 182;
    int n = 3;

    printf("x before rotating: %d\n", x);

    x = rightrot(x, n);

    printf("x after rotating: %d\n", x);

}
