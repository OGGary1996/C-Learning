# include <stdio.h>

// 传递二维数组到函数
void print_array (int (*arr)[4] , int rows) {
    for (int i = 0 ; i < rows ; i++) {
        for (int j = 0 ; j < 4 ; j++){
            printf("arr[%d][%d] = %d ",i,j,*(*(arr + i) + j));
        }
    }
}

// 传递不规则的二维数组到函数
void print_jagged_array(int* *arr,int rows, int* sub_arr_len) {
    for (int i = 0 ; i < rows ; i++) {
        for (int j = 0 ; j < *(sub_arr_len + i) ; j++) {
            printf("arr[%d][%d] = %d ",i,j,*(*(arr + i) + j));
        }
    }
}

int main() {
    // 2D array
    // 创建一个规则的二维数组
    int arr[3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
    };

    // 二维数组的指针
        // 通过指针来访问元素
    printf("Using array notation: %d.\n",arr[1][2]);
    printf("Using pointer notation: %d.\n",*(*(arr+1)+2));
    /*
    * arr 是二维数组的名称，它是一个指向第一行的指针，类型为 int (*)[4];指向一个包含4个int的数组int [4]。
    * arr + 1 是一个指针算术运算，它使指针向前移动一个完整的行，所以现在指向第二行的起始位置。这个表达式的类型仍然是 int (*)[4]。
    * *(arr + 1) 是对指针的解引用，它获取指针指向的内容，即第二行的整个数组。这个表达式的结果是一个 int [4] 类型的数组，即第二行。
    * ❗️❗️❗️在C语言中，数组名会自动衰减为指向其第一个元素的指针。所以 *(arr + 1) 在这里会衰减为 int* 类型，指向第二行的第一个元素。
    * *(arr + 1) + 2 是在第二行的起始位置上再偏移2个元素，所以现在指向第二行的第三个元素（索引为2）。这个表达式的类型是 int*。
    * 最后 *(*(arr + 1) + 2) 解引用这个指针，获取第二行第三个元素的值。
    */

        // 通过指针来遍历数组,此时使用sizeof中的arr不会退化为指针
    for (int i = 0 ; i < sizeof(arr)/sizeof(arr[0]) ; i++) {
        for (int j = 0 ; j < sizeof(arr[0])/sizeof(arr[0][0]) ; j++){
            printf("arr[%d][%d] = %d ",i,j,*(*(arr + i) + j));
        }
    }
    printf("\n");

        // 传递规则的二维数组到函数
    print_array(arr,sizeof(arr)/sizeof(arr[0]));
    printf("\n");



    // 不规则的二维数组，通过指针数组来实现
    int sub_arr_1[3] = {1,2,3};
    int sub_arr_2[5] = {4,5,6,7,8};
    int sub_arr_3[4] = {9,10,11,12};
        // 创建一个指针数组,将每个子数组的首地址存储在指针数组中
    int* arr_2[3] = {sub_arr_1,sub_arr_2,sub_arr_3}; // int* arr_2[3]代表了一个指针数组，跟传递到函数的数组指针不同
    printf("Using array notation: %d.\n",*(*(arr_2 + 1) + 2));
        // 遍历不规则的二维数组，！！！此时，如果想要计算每个子数组的长度，使用sizeof(arr_2[0])得到的结果是指针的长度，而不是子数组的长度，因为其本质上是一个指针
        // 所以，创建一个int数组来存储每个子数组的长度
    int array_len[3] = {sizeof(sub_arr_1)/sizeof(sub_arr_1[0]),sizeof(sub_arr_2)/sizeof(sub_arr_2[0]),sizeof(sub_arr_3)/sizeof(sub_arr_3[0])};
        // 在内层循环中使用array_len来遍历每个子数组
    for (int i = 0 ; i  < sizeof(arr_2)/sizeof(arr_2[0]) ; i++) {
        for (int j = 0 ; j < *(array_len + i) ; j++) {
            printf("arr_2[%d][%d] = %d ",i,j,*(*(arr_2 + i) + j));
        }
    }
    printf("\n");

        // 传递不规则的二维数组到函数
    print_jagged_array(arr_2,sizeof(arr_2)/sizeof(arr_2[0]) , array_len);


}




