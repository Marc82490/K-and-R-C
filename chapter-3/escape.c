#include <stdio.h>

void escape(char s[], char t[]) {
    int i, j, c;

    for (i, j = 0; t[i] != '\0'; i++, j++) {
        c = t[i];
        printf("c is: %c\n", c);
        switch (c) {
            case '\n':
                printf("1");
                s[j] = '\\';
                j++;
                s[j] = 'n';
                break;
            case '\t':
                printf("2");
                s[j] = '\\';
                j++;
                s[j] = 't';
                break;
            default:
                s[j] = c;
                break;
        }
    

    }
}

int main() {
    char t[] = "test	rest";
    char s[100];    

    escape(s, t);

    printf("%s\n", s);
 
    return 0;
}
