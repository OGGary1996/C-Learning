# include <stdio.h>

void print_MSG() {
    printf("Hello, World!\n");
}


// 1. 定义add、sub、mul、div函数
float add(float *num_1, float *num_2) {
    return *num_1 + *num_2;
}

float sub(float *num_1, float *num_2) {
    return *num_1 - *num_2;
}

float mul(float *num_1, float *num_2) {
    return *num_1 * *num_2;
}

float div(float *num_1, float *num_2) {
    return *num_1 / *num_2;
}


int main() {
    // 函数指针
        // 1. 定义函数指针
    void (*p)() = print_MSG;
        // 2. 使用函数指针
    p();

    // 函数指针数组
        // 1. 定义add、sub、mul、div函数
        // 2. 定义函数指针数组
    float (*function_pinter_array[4]) (float*,float*) = {add,sub,mul,div};
        // 3. 通过读取用户输入来判断调用哪个函数
    printf("Please enter two numbers: ");
    float num_1, num_2;
    scanf("%.2f",&num_1);
    scanf("%.2f",&num_2);
    printf("Please enter the operation you want to perform: ");
    int operation;
    scanf("%d",&operation);
    float result = (function_pinter_array[operation -1])(&num_1,&num_2);
    printf("The result is: %.2f\n",result);



    return 0;
}