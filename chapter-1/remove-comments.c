#include <stdio.h>

void remove_char(int c);

int main() {
    int c;
    int k;
    int state;

    state = 0;
    /* check each character until end of file */
    while ((c = getchar()) != EOF) {
        /* if you're in a comment, keep removing until the end of the comment */
        if (state == 1) {
            if (c == '*') {
                if ((k = getchar()) == '/') {
                    state = 0;
                }
                remove_char(c);
                remove_char(k);
            }
            else {
                remove_char(c);
            }
        }
        /* ignore an escape character and the following character */
        else if (c == '\\') {
            putchar(c);
            c = getchar();
            putchar(c);
        }
        /* check for the start of a comment */
        else if (c == '/') {
            k = getchar();
                /* check the next character to see if it's truly a comment; if it is, remove both
                    and set the state to be inside of a comment */
                if (k == '*') {
                    remove_char(c);
                    remove_char(k);
                    state = 1;
                }
        }
        /* in all other cases, print the character */
        else {
            putchar(c);
        }
    }
    return 0;
}

/* replace a character with an empty string */
void remove_char(int c) { 
    printf("");
}
