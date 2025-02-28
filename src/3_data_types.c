#include <stdio.h>

int main () {
    short num_1 = 10; // format specifier %d
    printf("The size of short is %zu bytes.\n" , sizeof(num_1));
    int num_2 = 10; // format specifier %d
    unsigned num_2_1 = 10; // unsigned means positive number
    printf("The size of int is %zu bytes.\n" , sizeof(num_2));
    float num_3 = 10.0F; // format specifier %f
    printf("The size of float is %zu bytes.\n" , sizeof(num_3));
    double num_4 = 10.0F; // format specifier %lf
    printf("The size of double is %zu bytes.\n" , sizeof(num_4));
    long num_5 = 10L; // format specifier %ld
    printf("The size of long is %zu bytes.\n" , sizeof(num_5));
    long long num_6 = 10LL; // format specifier %lld
    printf("The size of long long is %zu bytes.\n" , sizeof(num_6));

    char char_1 = 'A'; // format specifier %c
    printf("The size of char is %zu bytes.\n" , sizeof(char_1));
    char char_2 = 65; // we can use ASCII code to assign a char
    printf("ASCII code of %c is %d.\n",char_2,65);
    return 0;
}
