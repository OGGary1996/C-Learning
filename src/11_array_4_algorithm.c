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
    // 2. selection sort
void selection_sort(int *arr, int len) {
    for (int i = 0 ; i < len -1 ; i++){
        int min_index = i;
        for (int j = i + 1 ; j < len ; j++) {
            if (*(arr + j) < *(arr + min_index)) {
                int min_index = j;
            }
            int temp = *(arr + i);
            *(arr + i) = *(arr + min_index);
            *(arr + min_index) = temp;
        }
    }
}

    // 3. insertion sort
void insertion_sort(int *arr , int len) {
    for (int i = 1 ; i < len ; i++){
        int key = *(arr + i);
        int j = i - 1;
        while(j >= 0 && *(arr + j) > key){
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = key;
    }
}

    // 4. binary search
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

    // 5. merge two sorted arrays
void merge_arr(int *arr_1 , int len_1 , int *arr_2 , int len_2 , int *merged) {
    int i = 0;
    int j = 0;
    int k = 0;
    while(i >= len_1 || j >= len_2) {
        if (*(arr_1 + i) > *(arr_2 + j)){
            *(merged + k ) = *(arr_2 + j);
            k++;
            j++;
        }else {
            *(merged + k) = *(arr_1 + i);
            k++;
            i++;
        }
        while(i < len_1) {
            *(merged + k) = *(arr_1 + i);
            k++;
            i++;
        }
        while(j < len_2) {
            *(merged + k) = *(arr_2 + j);
            k++;
            j++;
        }
    }
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

    printf("After sort: ");
    //bubble_sort(arr_1,len_1);
    //selection_sort(arr_1,len_1);
    insertion_sort(arr_1,len_1);
    for (int i = 0 ; i < len_1 ; i++) {
        printf("arr[%d] = %d ",i,*(arr_1+i));
    }
    printf("\n");

    int arr_2[10] = {1,2,3,4,5,6,7,8,9,10};
    int len_2 = sizeof(arr_2)/sizeof(arr_2[0]);
    printf("Target: %d, Result: %d.\n",5,binary_search(arr_2,len_2,5));

    int arr_3[5] = {1,3,5,7,9};
    int arr_4[5] = {2,4,6,8,10};
    int merged[10];
    printf("After merge: ");
    merge_arr(arr_3,5,arr_4,5,merged);
    for (int i = 0 ; i < 10 ; i++) {
        printf("merged[%d] = %d ",i,*(merged+i));
    }


    return 0;
}