#include <stdio.h>

void function_1 (int num_1,int num_2) {
    // 函数体
}

void function_2 (int num_1,int num_2) {
    // 函数体
}

void function_3 (int num_1,int num_2) {
    // 函数体
}


int main () {
    // 1. 定义指针到变量
    int num = 10;
    int *p_num = &num;

    // 2.定义指针指向数组
    int arr_1[] = {1, 2, 3, 4, 5};
    int *p_arr = arr_1;

    // 3. 定义指针指向二维数组
    int arr_2[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int (*p_arr_2)[3] = arr_2;

    // 4.定义指针指向函数
    void (*p_function) (int,int) = function_1;

    // 5.定义指针指向指针数组
    int* (*p_arr_p);

    // 6.定义指针指向函数指针数组
        //1.定义函数指针数组
    void (*finction_arr[3])(int ,int ) = {function_1, function_2, function_3};
        //2.定义指针指向函数指针数组
    void *(*p_function_arr)(int ,int ) = finction_arr;

    return 0;
}