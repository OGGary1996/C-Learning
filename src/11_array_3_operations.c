#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// 数值的常见操作
    // 1. 数组的最大值和最小值
int arr_max (int *arr , int len) {
    int max = *arr;
    for (int i = 0 ; i < len ; i++) {
        if (*(arr + i) > max) {
            max = *(arr+i);
        }
    }
    return max;
}
int min_arr(int *arr , int len) {
    int min = *arr;
    for (int i = 0 ; i < len ; i++) {
        if (*(arr + i) < min) {
            min = *(arr+i);
        }
    }
    return min;
}
    // 2. 数组的平均值
double avg_arr(int *arr , int len) {
    int sum = 0;
    for (int i = 0 ; i < len ; i++) {
        sum += *(arr + i);
    }
    return sum/(double)len;
}

    //3.反转数组
void reverse_arr(int *arr,int len) {
    int left = 0;
    int right = len-1;
    while (left < right) {
        int temp = *(arr + left);
        *(arr + left) = *(arr + right);
        *(arr + right) = temp;
        left++;
        right--;
    }
}

    // 4.在数组中插入元素
void insert_arr(int *arr, int len, unsigned int position,int value) {
    if (position >= len) {
        printf("Index overflow!\n");
    }else {
        // 正向插入
        int temp_1 = *(arr + position);
        *(arr + position) = value;
        for (int i = position + 1 ; i <= len ; i++) {
            int temp_2 = *(arr + i);
            *(arr + i) = temp_1;
            temp_1 = temp_2;
        }
        //逆向插入
        // for (int i = len ; i >= position ; i--) {
        //     *(arr + i) = *(arr + i - 1);
        // }
    }
}

    // 5.删除数组中的元素
void delete_arr(int *arr,int len, unsigned int position) {
    if (position >= len) {
        printf("Index overflow!\n");
    }else {
        // 正向删除
        // for (int i = position ; i < len - 1 ; i++) {
        //     *(arr + i) = *(arr + i + 1);
        // }
        // 逆向删除
        int temp_1 = *(arr + len - 1);
        for (int i = len -1 ; i > position ; i--) {
            int temp_2 = *(arr + i - 1);
            *(arr + i - 1) = temp_1;
            temp_1 = temp_2;
        }
    }
}

int main () {
    // 通过随机数定义数组
    int arr_1[10];
    int len_1 = sizeof(arr_1)/sizeof(arr_1[0]);
    srand(time(NULL));
    for (int i = 0 ; i < len_1 ; i++){
        *(arr_1 + i) = rand() % 100 + 1; // 生成1-100的随机数
        printf("arr[%d] = %d. ", i , *(arr_1 + i));
    }
    printf("\n");
    printf("Max: %d , Min: %d.\n",arr_max(arr_1,len_1),min_arr(arr_1,len_1));

    printf("Avg: %lf.\n",avg_arr(arr_1,len_1));

    reverse_arr(arr_1,len_1);
    printf("After reverse:\n");
    for (int i = 0 ; i < len_1 ; i++) {
        printf("arr[%d] = %d. ",i,*(arr_1 + i));
    }
    printf("\n");

    insert_arr(arr_1,len_1,1,100);
    printf("After insert:\n");
    for (int i = 0 ; i <= len_1 ; i++) {
        printf("arr[%d] = %d. ",i,*(arr_1 + i));
    }
    printf("\n");

    delete_arr(arr_1,len_1,2);
    printf("After delete:\n");
    for (int i = 0 ; i < len_1 ; i++) {
        printf("arr[%d] = %d. ",i,*(arr_1 + i));
    }
    printf("\n");



    return 0;
}