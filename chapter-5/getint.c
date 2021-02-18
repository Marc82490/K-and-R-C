#include <stdio.h>
#include <ctype.h>


int getint(int *pn) {
    int c, sign;

    while (isspace(c = getchar())){
        ;
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetc(c, stdin);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getchar();
    }
    if (!isdigit(c)) {
        ungetc(c, stdin);
    }
    for (*pn = 0; isdigit(c); c = getchar()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
        ungetc(c, stdin);
    }
    return c;
}

int main(void){
    int n, array[10], getint(int *);
    
    for (n = 0; n < 10 && getint(&array[n]) != EOF; n++) {
        ;
    }
    
    for (n = 0; n < 10; n++) {
        printf("%d \t", array[n]);
    }
    printf("\n");
}
