#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]) {
    int i, j, k;

    for (i = strlen(s)-1; s[i] != '\0'; i--) {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++ ) {
            ;
        }
        if (k > 0 && t[k] == '\0') {
            return i;
        }
    }
    return -1;
}

int main() {
    int index = 0;
    char pattern[] = "ould";
    char line[] = "would could should";

    index = strindex(line, pattern);

    printf("%d\n", index);

    return index;
}
