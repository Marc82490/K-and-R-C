#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i], s[i] = s[j], s[j] = c;
    }
}

int itob(int n, char s[], int b) {
    int i, sign;
    char c;

    if ((sign = n) < 0) {
        n = -n;
    }
   
    i = 0; 
    
    do {
        c = n % b;
        if (c >= 10) {
            c = c - 10 + 'a';
        }
        else {
            c = c + '0';
        } 
        s[i++] = c;
    } while ((n /= b) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    
    s[i] = '\0';
    reverse(s);

    return 0;
}

int main() {
    int n = 100;
    char s[100];
    int b = 16;

    itob(n, s, b);

    printf("%s\n", s);

    return 0;
}
