#include <stdio.h>

void ptrstrcat(char *s, char *t){
    while (*s != '\0') {
        s++;
    }
    while ((*s++ = *t++) != '\0'){
    }
}

int main(void){
    char s[] = "test";
    char t[] = "ees";

    ptrstrcat(s, t);
    printf("%s\n", s);

    return 0;
}
