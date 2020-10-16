#include <stdio.h>
#include <stdlib.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;              /* lower limit of temperature table */
    upper = 300;            /* upper limit */
    step = 20;              /* step size */

    fahr = lower;
    
    printf("Fahr  Cels\n");
    while (fahr <= upper) {
        celsius = (5.0 / 9.0 ) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    
    /* reset and print conversion from Celsiu to Fahrenheir */
    lower = 0;
    upper = 150;
    step = 10;

    celsius = lower;

    printf("\n");
    printf("Cels Fahr\n");
    while (celsius <= upper) {
        fahr = ((9.0 / 5.0) * celsius ) + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return EXIT_SUCCESS;
}
