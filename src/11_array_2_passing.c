#include <stdio.h>

void arr_len(int arr[]){
    int len = sizeof(arr)/sizeof(arr[0]); // 实际上是指针大小 / 元素大小 = 8bytes / 4bytes = 2
    printf("The incorrect length of arr is %d.\n",len);
}

// 通过内存地址传递数组
void modify_arr(int *arr , int len) {
    *arr = 10;
}

int main() {
    // 数组在传递时会退化为指针，所以在函数中传递数组时，实际上是传递了数组的首地址
    // 必须同时传递数组的长度，否则在函数中无法获取数组的长度
    int arr[] = {1,2,3,4,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("The correct length of arr is %d.\n",len);
    arr_len(arr);
    modify_arr(arr,len);
    for (int i = 0 ; i < len ; i++) {
        printf("arr[%d] = %d , Address = %p.\n",i,*(arr+i),arr+i);
    }

    return 0;
}