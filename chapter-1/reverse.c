#include <stdio.h>
#define MAXLINE 1000

int getline_2(char line[], int maxline);
void reverse(char line[], int lim);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = getline_2(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("%s\n", line);
    }
    return 0;
}

int getline_2(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;

}

void reverse(char s[], int lim) {
    char temp;
    int j = lim - 1;

    for (int i = 0; i < (lim / 2); ++i, --j) {
        temp = s[i]; 
        s[i] = s[j];
        s[j] = temp;
    }
}
