#include <stdio.h>

int main() {
    // 访问数组元素的内存地址
    int arr[5] = {1,2,3,4,5};
    for (int i = 0 ; i < sizeof(arr)/sizeof(arr[0]) ; i++){
        printf("arr[%d] = %d, Address = %p.\n",i,arr[i],&arr[i]);
    }

    // 通过指针访问数组的元素
        // 在C语言中，数组名是一个指向数组首元素的指针常量，所以 arr = &arr[0]
    int *p = arr; // 获取首地址
    printf("First address: %p.\n",p);
    for (int i = 0 ; i < sizeof(arr)/sizeof(arr[0]); i++) {
        // 通过首地址+1的方式访问数组元素
        printf("arr[%d] = %d , Address = %p.\n", i , *(p+i) , p+i);
    }
        // p+1 中的1并不表示加1，而是加一个元素类型的数据长度，所以 p+1 = p+sizeof(int)，C中会自动计算数据类型的长度

        // 在C中，arr[i] = *(arr + i);
    for (int i = 0 ; i < sizeof(arr)/sizeof(arr[0]); i++) {
        printf("arr[%d] = %d , Address = %p.\n",i , *(arr + i) , arr + i);
    }

    return 0;
}