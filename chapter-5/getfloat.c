#include <stdio.h>
#include <ctype.h>


int getfloat(int *pn) {
    int c, sign;

    while (isspace(c = getchar())){
        ;
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetc(c, stdin);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getchar();
    }
    if (!isdigit(c) && c != '.') {
        ungetc(c, stdin);
    }
    if (isdigit(c)) {
        for (*pn = 0; isdigit(c); c = getchar()) {
            *pn = 10 * *pn + (c - '0');
        }
    }
    if (c == '.') {
        for (*pn; isdigit(c); c = getchar()) {
            *pn = 10 / *pn + (c - '0');
        }
    }
    *pn *= sign;
    if (c != EOF) {
        ungetc(c, stdin);
    }
    return c;
}

int main(void){
    int n, array[10], getfloat(int *);
    
    for (n = 0; n < 10 && getfloat(&array[n]) != EOF; n++) {
        ;
    }
    
    for (n = 0; n < 10; n++) {
        printf("%d \t", array[n]);
    }
    printf("\n");
}
