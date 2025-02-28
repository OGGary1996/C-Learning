#include <stdio.h>

int main () {
    // 定义数组并初始化
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    printf("First eliment of array is %d.\n",arr[0]);
    printf("Second eliment of array is %d.\n",arr[1]);
        // 也可以在定义的时候先不写长度，这时候编译器会根据初始化的元素个数自动计算长度
    int arr_2[] = {0,1,2,3,4}; // 这里的长度是5
        // 也可以在定义大小之后少输出元素，未被赋值的元素会有默认值

    // 数组的遍历与修改和Java类似。。。。

    // 多维数组
    // 定义二维数组
    int multi_arr[2][3] = {{11,12,13},{22,22,23}};
        // 访问修改二维数组以及遍历
    printf("The first eliment of this array is %d.\n",multi_arr[0][0]);
        // 使用嵌套循环遍历
    for (int i = 0 ; i < sizeof(multi_arr)/sizeof(multi_arr[0]); i++){
        for (int j = 0 ; j < sizeof(multi_arr[0])/sizeof(multi_arr[0][0]); j++){
            printf("The eliment of this array is %d.\n",multi_arr[i][j]);
        }
    }

    return 0;
}