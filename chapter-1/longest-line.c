#include <stdio.h>
#define MAXLINE 10 

int getline_2(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;
    int max;
    int num_len;
    char line[MAXLINE];
    char longest[MAXLINE];

    while ((len = getline_2(line, MAXLINE)) > 0) {
        num_len = 0;
        while (line[len-1] != '\n') {
            ++num_len;
            len = getline_2(line, MAXLINE); 
        }
        len = len + (num_len * (MAXLINE-1));
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("%d\n", max);
        printf("%s", longest);
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

void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
