#include <stdio.h>
#define TRUE 1
#define FALSE 0

int any(char s1[], char s2[]) {
    int i, j, k;
    int flag = FALSE;

    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);
    
    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                printf("Character in s1: %c\n", s1[i]);
                printf("Index of s1: %d\n", i);
                printf("Character in s2: %c\n", s2[j]);
                printf("Index of s2: %d\n", j);
                flag = TRUE;
                break; 
            }
        }
        if (flag == TRUE) {
            break;
        }
    }
    
    if (flag == FALSE) {
        i = -1;
    }

    return i;
}

int main() {
    char a[] = "cat";
    char b[] = "ark";
    int position;

    printf("First string: %s\n", a);
    printf("Second string: %s\n", b);

    position = any(a, b);

    printf("The first character is in position: %d\n", position);
}
