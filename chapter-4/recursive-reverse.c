#include <stdio.h>
#include <string.h>

void reverse(char s[], int left, int right) {
    int temp;

    if (left < right) {
        reverse(s, left+1, right-1); 
    } 
    temp = s[left];
    s[left] = s[right];
    s[right] = temp;
}

int main() {
    char s[] = "asdf";

    reverse(s, 0, (strlen(s)-1));

    printf("s after reversing: %s\n", s);
}
