#include <stdio.h>

int strend(char *s, char *t){
    /* Loop through s until we see t
        Loop unntil s == first char in t,
        Sub loop to check each next char
        If any chars dont match, break
    If s and t end at the same time, return 1 */

    while (*s != '\0') {
        if (*s == *t) {
            for (; *s == *t; s++, t++) {
                if (*s == '\0' && *t == '\0') {
                    return 1;
                }
            }
        }
        s++;
    }
}

int main(void){
    char s[] = "testees";
    char t[] = "es";

    printf("%d\n",strend(s, t));

    return 0;
}

