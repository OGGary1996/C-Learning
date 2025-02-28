#include <stdio.h>

int main() {
    // 算数运算符
    // 与java完全一致，只是不会自动转换float/double类型，需要手动转换
    int a = 5;
    int b = 2;
    float c = a / (float)b;
    printf("c = %.2f \n",c);
    // 赋值，比较，逻辑运算符与java一致

    // 位运算符
    // 与java一致，只是没有>>>运算符
    int d = 60; // 0011 1100
    int e = 13; // 0000 1101
    // 1. 按位与运算符（&）: 如果相对应位都是1，则结果为1，否则为0
    int f = d & e; // 0000 1100
    printf("f = %d \n",f);
    // 2. 按位或运算符（|）: 如果相对应位有1，则结果为1，否则为0
    int g = d | e; // 0011 1101
    printf("g = %d \n",g);
    // 3. 按位异或运算符（^）: 如果相对应位值不同，则结果为1，相同为0
    int h = d ^ e; // 0011 0001
    printf("h = %d \n",h);
    // 4. 按位取反运算符（~）: 将每个位都取反
    int i = ~d; // 1100 0011
    printf("i = %d \n",i);
    // 。。。。 与java一致

    // 其他运算符
    // 1.三元运算符，与java完全一致
    int num_1 = 10;
    int num_2 = 20;
    int max = (num_1 > num_2) ? num_1 : num_2;
    printf("Max number is %d \n",max);
    // 2. sizeof运算符，与java不同，java没有sizeof运算符
    int num_3 = 10;
    printf("The size of int is %zu bytes.\n" , sizeof(num_3));
    // 3. 逗号运算符，与java不同，java没有逗号运算符
    int num_4 = (1,2,3,4,5);
    printf("num_4 = %d \n",num_4);
    // 4. 指针运算符，与java不同，java没有指针运算符
    char char_1 = 'A';
    char *p = &char_1; // 通过指针访问变量的值
    printf("The value of char_1 is %c \n",*p);

    return 0;
}
