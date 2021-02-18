#include <stdio.h>
#include <ctype.h>

/* Takes a hex string and returns the decimal value */
int hextoi(char s[]) { 
    int i;
    int j;
    int result = 0;

    /* Loop until end of string */
    while (s[i] != '\0') {
        j = s[i];
        i++;
        /* Check for A-F and the optional 'X' that marks hex strings */
        if (isalpha(j)) {
            j = tolower(j);
            /* If 'X', we know we don't need to include its numeric value in the result */
            if (j == 'x') {
                continue;
            }
            /* For all other characters, add the value for A = 10 ... F = 15 */
            j = j - 'a' + 10;
        }
        /* Add digit values as they are */
        else if (isdigit(j)) {
            j = j - '0';
        }
        result = result + j;
    }
    return result;
}

int main(void){
    char test_string[] = "0X123AF";

    printf("%d\n", hextoi(test_string));
    
    return 0;
}
