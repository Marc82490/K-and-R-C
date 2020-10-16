#include <stdio.h>

int main() {
    int c;
    char flag;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            flag = 1;
            continue;
        }
    
        if (flag == 1) {
            printf(" ");
            flag = 0;
        }

    putchar(c);
    }

return 0;
}
