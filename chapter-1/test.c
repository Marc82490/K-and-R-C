#include <stdio.h>

/*
main()
c, k

state = out
while c = getchar != EOF
    if state == in
        if c == *
            if k = getchar == /
                state = out
            remove c, k
        else 
            remove c
    else if char == \
        putchar
        c = getchar
        putchar
        continue
    else if char == /
        k = getchar
            if k == *
                remove c, k
                state = in
    else
        putchar
*/
void remove_char(int c);

int main() {
    int c;
    int k;
    int state;

    state = 0;
    while ((c = getchar()) != EOF) {
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
        else if (c == '\\') {
            putchar(c);
            c = getchar();
            putchar(c);
        }
        else if (c == '/') {
            k = getchar();
                if (k == '*') {
                    remove_char(c);
                    remove_char(k);
                    state = 1;
                }
        }
        else {
            putchar(c);
        }
    }
    return 0;
}

void remove_char(int c) { 
    printf("");
}
