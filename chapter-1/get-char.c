#include <stdio.h>

int main() {
    int c;
    
    c = EOF;
    printf("%d", c);
 
    while (c = getchar() != EOF) {
        printf("%d",c); 
    }

return 0;
}
