#include <stdio.h>
#define TAB_WIDTH 5

/*
while getchar != EOF
    if char != \t
        increment space_counter
        print char
    else
        while space_counter % tab_width != 0 
            print space
*/

int main(void) {
    int c;
    int spaces;

    spaces = 0;
    while ((c = getchar()) != EOF) {
        ++spaces;
        if (c == '\t') {
            while ((spaces % (TAB_WIDTH+1)) != 0) {
                printf(" ");
                ++spaces;
            }
        }
        else if (c == '\n') {
            putchar(c);
            spaces = 0;
        }
        else {
            putchar(c);
        }
    }
    return 0;
}
