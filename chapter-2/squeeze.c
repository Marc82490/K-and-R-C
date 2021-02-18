#include <stdio.h>
#define TRUE 1
#define FALSE 0

void squeeze(char s1[], char s2[]) {
    int i, j, k;
    int flag = FALSE;

    for (i = k = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                flag = TRUE;
            }
        }
        if (flag == FALSE) {
            s1[k++] = s1[i];
        }
        flag = FALSE;
    }
    s1[k] = '\0';
}

int main() {
    char a[] = "character";
    char b[] = "crock";

    printf("string to squeeze from: %s\n", a);
    printf("characters to delete: %s\n", b);

    squeeze(a, b);

    printf("final string: %s\n", a);
}
