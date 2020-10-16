#include <stdio.h>
#include <stdlib.h>

float convert_to_cels(float temp_f);
float convert_to_fahr(float temp_c);

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
        celsius = convert_to_cels(fahr);
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
        fahr = convert_to_fahr(celsius);
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return EXIT_SUCCESS;
}

float convert_to_cels(float temp_f) {
    return (5.0 / 9.0) * (temp_f - 32.0);
}

float convert_to_fahr(float temp_c) {
    return ((9.0 / 5.0) * temp_c ) + 32.0;
}
