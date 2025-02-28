# include <stdio.h>
# include <stdlib.h>
# include <time.h>

// C中的数组相关的经典算法：
    // 1. bubble sort
void bubble_sort(int *arr , int len) {
    for (int i = 0 ; i < len - 1 ; i++) {
        for (int j = 0 ; j < len - 1 - i ; j++) {
            int temp = *(arr + j);
            if (*(arr + j) > *(arr + j + 1)) {
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

    // 2. binary search
    // iterative
int binary_search(int *arr , int len , int target) {
    int left = 0;
    int right = len-1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if ( *(arr + middle)== target) {
            return *(arr + middle);
        } else if ( *(arr + middle) < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;
}
    // recursive
int binary_search_recursive (int *arr, int len, int left , int right , int target) {
    int middle = left + (right - left) / 2;
    if (*(arr + middle) == target) {
        return *(arr + middle);
    } else if (*(arr + middle) < target) {
        binary_search_recursive(arr, len, middle + 1, right, target);
    } else {
        binary_search_recursive(arr, len, left, middle - 1, target);
    }
    return -1;
}

int main() {
    // 通过随机数定义数组
    int arr_1[10];
    int len_1 = sizeof(arr_1)/sizeof(arr_1[0]);
    srand(time(NULL));
    printf("Origin array:\n");
    for (int i = 0 ; i < len_1 ; i++){
        *(arr_1 + i) = rand() % 100 + 1 ; // 生成1-100的随机数
        printf("arr[%d] = %d ",i,*(arr_1+i));
    }
    printf("\n");

    printf("After bubble sort: ");
    bubble_sort(arr_1,len_1);
    for (int i = 0 ; i < len_1 ; i++) {
        printf("arr[%d] = %d ",i,*(arr_1+i));
    }
    printf("\n");

    int arr_2[10] = {1,2,3,4,5,6,7,8,9,10};
    int len_2 = sizeof(arr_2)/sizeof(arr_2[0]);
    printf("Target: %d, Result: %d.\n",5,binary_search(arr_2,len_2,5));


    return 0;
}