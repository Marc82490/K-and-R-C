#include <stdio.h>

void itoa(int n, char s[]) {
    int sign;
    static int i;

    if ((sign = n) < 0) {
        n = -n;
        i = 1;
    }
    
    if (n / 10) {
        itoa(n / 10, s);
    }
    s[i++] = n % 10 + '0';
    if (sign < 0) {
        s[0] = '-';
    }
    s[i] = '\0';
}

int main() {
    char s[100];
    int n = -19;
    
    itoa(n, s);
    printf("s after converting n: %s\n", s);
}
