#include <stdio.h>
#include <math.h>

unsigned invert(unsigned x, int p, int n) {
    /* Create a bitmask with the rightmost p bits set to 1s */
    unsigned y = (int) (pow(2, (p+1))-1);

    /* Create a second bitmask with the rightmost p-n+1 bits set to 1s */
    unsigned w = (int) (pow(2, (p-n+1))-1);

    /* Subtract the second bitmask from the first, such that the bitmask has 1s in the n bits starting
       at position p */
    y = y - w;

    /* XOR the input bitstring against the bitmask to flip the values of the n bits starting at position p */
    x = x ^ y;

    return x;
}

int main() {
    unsigned x = 182;
    int p = 5;
    int n = 4;
    
    printf("x before flipping: %d\n", x);

    x = invert(x, p, n);

    printf("x after flipping: %d\n", x);
}
