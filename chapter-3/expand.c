#include <stdio.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0

void expand(char s1[], char s2[]) {
    int i, j, k, c;
    int flag = FALSE;

    for (i, j = 0; s1[i] != '\0'; i++, j++) {
        c = s1[i];
        if (c == '-') {
            if (s1[i-1] != ' ' && s1[i+1] != ' ') {
                s2[j-1] = s1[i-1];
                for (k = s1[i-1] + 1; k < s1[i+1]; k++, j++) {
                    s2[j] = k;
                }
                s2[j] = s1[i+1];
                flag = TRUE;
                continue;
            }
        }
        if (!flag) {
            s2[j] = c;
        }        
        else {
            j--;
            flag = FALSE;
        }
    }
    s2[j] = '\0'; 

}

int main() {
    /*
    char s1[] = "a-z";
    char s2[100];

    expand(s1, s2);

    printf("%s\n", s2);
    */ 
    char s3[] = "0-9a-z";
    char s4[100];

    expand(s3, s4);

    printf("%s\n", s4);

    return 0;
}
