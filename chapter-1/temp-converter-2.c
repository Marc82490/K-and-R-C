#include <stdio.h>
#include <stdlib.h>

/* print Fahrenheit-Celsius table */
int main() {
    for (int fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }

    /* print in opposite direction */
    printf("\n");
    for (int fahr = 300; fahr >= 0; fahr = fahr - 20) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }

return EXIT_SUCCESS;
}
