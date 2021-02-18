#include <ctype.h>
#include <stdio.h>

double atof(char s[]) {
    double val, power, exp, result;
    int i, j, sign, exp_sign;

    for (i=0; isspace(s[i]); i++) {
        ;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    result = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-') {
            i++;
        }
        for (exp = 0.0; isdigit(s[i]); i++) {
            exp = 10.0 * exp + (s[i] - '0');
            printf("%lf\n", exp);
        }
        for (j=0; j < exp; j++) {
            if (exp_sign == -1) {
                result /= 10;
            }
            else {
                result *= 10;
            }
            printf("%lf\n", result);
        }
    }
    
    return result;
}

int main() {
    char s[] = "12.234e-10";
    double i;

    i = atof(s);
    printf("%.15f\n", i);

    return 0;
}
