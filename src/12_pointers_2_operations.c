# include <stdio.h>

// 作用1: 通过指针，直接在函数中操作变量的值
// 在C中，参数传递是值传递，即传递的是变量的值，而不是变量的地址
    // Example 1，普通方式无法通过函数修改值
void swap_notworking(int num1, int num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
    // Example 2，通过指针，可以通过函数修改值,直接传递变量的内存地址
void swap (int* p1 , int* p2) {
    int temp = *p1; // *p1 表示取出p1指针变量所指向的内存地址的值
    *p1 = *p2; // 将p2指针变量所指向的内存地址的值赋值给p1指针变量所指向的内存地址
    *p2 = temp; // 将temp的值赋值给p2指针变量所指向的内存地址
}

// 作用2: 通过指针，让函数“返回”多个值
// 实际上是通过将多个值的地址传递给函数，在函数中操作这些地址使得原来的变量发生了改动
    // example1 同时求数组的最大最小值
void extrem_value(int* arr, int len , int* max_address , int* min_address ) {
    for (int i = 0 ; i < len ; i++) {
        if (*(arr + i) > *max_address) {
            *max_address = *(arr + i);
        }
    }
    for (int i = 0 ; i < len ; i++) {
        if (*(arr + i) < *min_address) {
            *min_address = *(arr + i);
        }
    }
}

// 作用3: 将函数的结果和状态进行分离
int divide(int num1 , int num2 , float* result) {
    if (num2 == 0) {
        return 0;
    }else {
        *result = num1 / (float)num2;
        return 1;
    }
}


int main() {
    int a = 100;
    int b = 200;
    printf("Before swap: a = %d, b = %d.\n",a,b);
    swap_notworking(a,b);
    printf("After swapL: a = %d, b = %d.\n",a,b); // 无法通过函数修改值
    swap(&a,&b);
    printf("After swap: a = %d, b = %d.\n",a,b); // 通过指针，可以通过函数修改值
    printf("------------------------------------\n");

    int array_1[] = {1, 2, 3, 4, 5};
    int len = sizeof(array_1)/sizeof(array_1[0]);
    int max = array_1[0];
    int min = array_1[0];
    extrem_value(array_1,len,&max,&min);
    printf("Max value: %d, Min value: %d.\n",max,min);
    printf("------------------------------------\n");

    int num_1 = 10;
    int num_2 = 1;
    float result = 0;
    if (divide(num_1,num_2,&result)) {
        printf("Division success, Result: %.2f.\n",result);
    }else {
        printf("Division failed, Denominator cannot be 0.\n");
    }

    return 0;
}