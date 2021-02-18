#include <stdio.h> 
#include <limits.h>
#include <float.h>

int main(void) {
    printf("The min of signed char is: %d\n", SCHAR_MIN); 
    printf("The max of signed char is: %d\n", SCHAR_MAX);
    printf("The max of unsigned char is: %u\n", UCHAR_MAX); 
    printf("The min of signed int is: %d\n", INT_MIN);
    printf("The max of signed int is: %d\n", INT_MAX);
    printf("The max of unsigned int is: %u\n", UINT_MAX);
    printf("The min of signed short is: %d\n", SHRT_MIN);
    printf("The max of signed short is: %d\n", SHRT_MAX);
    printf("The max of unsigned short is: %u\n", USHRT_MAX);
    printf("The min of signed long is: %ld\n", LONG_MIN);
    printf("The max of signed long is: %ld\n", LONG_MAX);
    printf("The max of unsigned long is: %lu\n", ULONG_MAX);
    printf("The min of float is: %f\n", FLT_MIN);
    printf("The max of float is: %f\n", FLT_MAX);
    printf("The min of double is: %lf\n", DBL_MIN);
    printf("The max of double is: %lf\n", DBL_MAX);
    
    return 0;
}
