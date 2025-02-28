#include <stdio.h>

// 函数的声明 + 定义
void birthday(char name[],int age) {
    printf("Happy birthday %s ! You are now %d years old!\n",name,age);
}

// Example 1: 先声明，后定义,定义的位置一般在 main之后
double square(double);

//Example 2: 判断两个矩形面积大小,若前者大，返回1
int area_compare(double width_1, double length_1, double width_2, double length_2) {
    return (width_1 * length_1 > width_2 * length_2) ? 1 : 0;
}

// 递归函数
    // 1. 计算阶乘
int factorial(int);

    // 2. 斐波那契数列，计算第n个数
int fibonacci(int);


int main() {
    char name[] = "KE";
    int age = 28;
    // call example 1
    birthday(name,age);
    // call example 2
    double x = 2.0;
    printf("Result: %.2f.\n",square(x));
    // call example 3
    double width_1, length_1, width_2, length_2;
    printf("Please input the width and length of the first rectangle: ");
    scanf("%lf %lf",&width_1,&length_1);
    printf("Please input the width and length of the second rectangle: ");
    scanf("%lf %lf",&width_2,&length_2);
    (area_compare(width_1,length_1,width_2,length_2) == 1) ? printf("The first rectangle is larger.\n") : printf("The second rectangle is larger.\n");


    // 递归函数调用
    printf("Result of 5's factorial: %d.\n",factorial(5));
    printf("Result of 10th fibonacci number: %d.\n",fibonacci(10));

    return 0;
}

// 定义函数
double square(double x) {
    return x*x;
}

// 定义阶乘递归函数
int factorial(int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorial(n-1);
}
// 定义斐波那契数列递归函数
int fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}