# include <stdio.h>

int* modify () {
    int a = 100;
    return &a;
}

void swap (void* p1 , void* p2 , int size) {
    // 因为void*无法直接解构，所以我们通常将他转换为char*指针,因为char*指针的大小是1,便于计算
    char* pc1 = p1;
    char* pc2 = p2;
    // 在根据想要转换的具体数据类型，传递该数据类型的步长，一步一步完成byte的替换，实现数据的交换
    for (int i = 0 ; i < size ; i++) {
        char temp = *(pc1 + i);
        *(pc1 + i) = *(pc2 + i);
        *(pc2 + i) = temp;
    }
}

// 也可以通过多级指针直接修改最终指向变量的值
void multi_modify(int** pp) {
    static int new_num = 200;
    *pp = &new_num; // 使用*解构一次，得到一级的指针变量，然后将新的内存地址赋值给这个一级指针变量，此时一级指针指向了新的内存地址new_num
}

int main() {
    // 1. 野指针 uninitialized pointer
        // 指的是指针变量没有初始化，即指针变量没有指向任何一个内存地址
        // 或者是超出了指针变量的作用范围，比如数组索引越界
    // int* p; // 未初始化的指针变量
    // *p = 10;  野指针，未初始化的指针变量指向了一个内存地址，但是这个内存地址不属于这个指针变量，所以会报错
    // printf("%d\n",*p);

    // 2. 悬空指针 dangling pointer
        // 指的是指针变量指向的内存地址已经被释放了，但是指针变量还保留着这个内存地址
        // 通常在函数结束之后，函数中的变量结束生命周期被释放内存，但是指针变量还保留着这个内存地址
    int* p2 = modify();
    printf("Wait for a moment.\n");
    printf("%d\n",*p2); // 10

    // 3. void* 指针
        // void* 指针是一种特殊的指针类型，可以指向任何类型的数据
        // 但是不能直接操作void*指针所指向的内存地址，因为void*指针不知道所指向的内存地址的类型
    int a = 10;
    int* p1 = &a;
    void* p3 = p1;
    char* p4 = (void*) p1; // 通过强制类型转换，可以将void*指针转换为其他类型的指针
        // 通过void*指针，可以实现函数的多态，即函数可以接受任何类型的数据
        // 我们可以优化之前的swap()函数，使其可以接受任何类型的数据
    long long num_1 = 100;
    long long num_2 = 200;
    swap(&num_1,&num_2,sizeof(long long));
    printf("num_1 = %lld, num_2 = %lld.\n",num_1,num_2);

    // 4.二级指针
        // 二级指针是指指针变量的指针变量
    int num = 100;
    int* p = &num;
    int** pp = &p;
    printf("num's address: %p.\n", p);
    printf("int* p's address: %p.\n",pp);
    printf("num = %d.\n",**pp); // 通过二级指针，也可以访问到num的值

    multi_modify(pp); // 修改了一级指针变量的指向，！！！并未修改num的值
    printf("num = %d.\n",num); // num仍然是100

    int num_new = 200;
    **pp = num_new; // 此时通过二级指针，直接修改了num的值


    return 0;
}