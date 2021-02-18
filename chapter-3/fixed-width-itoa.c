#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int c, i, j;
    
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i], s[i] = s[j], s[j] = c;
    }
}

void itoa(int n, char s[], int w) {
    int i, sign;

    if ((sign = n) < 0) {
        n = -n;
    }

    i = 0;

    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    
    if (i < w) {
        for (; i < w; i++) {
            s[i] = ' ';
        }
    }
    
    s[i] = '\0';

    reverse(s);
}

int main() {
    int n = 69;
    char s[100];
    int w = 6;

    itoa(n, s, w);

    printf("%s\n", s);

    return 0;
}
