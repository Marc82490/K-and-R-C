#include <stdio.h>
#include <math.h>
#include <limits.h>

unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    /* get the rightmost n bits from y */
    unsigned z = getbits(y, n-1, n);
    /* create a bitmask with the leftmost bits set to ones */
    unsigned w = 65535 << p;

    printf("w after high order bits set: %d\n", w);
    /* set the n bits starting at position p in the bitmask to 0s */
    w = w | (int) (pow(2, (p-n+1))-1);
    printf("w after low order bits set: %d\n", w);    

    /* move the n bits taken from y to position p */
    z = z << (p-n+1);
    printf("z after moving bits: %d\n", z);

    /* mask x such that x equals x with the n bits starting at position p set to 0s */
    x = x & w;
    printf("x after masking: %d\n", x);

    /* copy the n bits taken from y into the n bits starting at position p in x */
    x = x | z;
    printf("x after setting middle bits: %d\n", x);

    return x;
}

int main() {
    unsigned x = 212;
    unsigned y = 171;
    int p = 5;
    int n = 4;

    x = setbits(x, p, n, y);
    printf("%d\n", x);
}
