# include <stdio.h>
# include <stdlib.h>

int main(){
    // 1. malloc() function
    /*
        1. 创建的空间单位是字节
        2. 返回的是 void* 类型指针，需要强制类型转换，
        3. 返回的是首地址，没有总的大小，最好是单独定义一个变量来存储大小
        4. 使用结束之后不会自动清除，需要手动释放，否则会造成内存泄漏
        5. 如果申请过多的空间，会产生虚拟内存
        6. 申请的空间没有进行初始化，里面的值是随机的
        7. free释放之后，指针不会变成NULL，但是指针指向的地址已经被释放，再次使用会报错
     */
    const int count = 10;
    int *ptr = (int *)malloc(count * sizeof(int)); // 申请了10个int类型的空间，也就是10*4bytes = 40bytes
    printf("Size: %lu\n",sizeof(ptr)); // 此时的大小是指针的大小，64位系统下是8bytes，不是申请的空间大小
    printf("Size in total: %lu\n",count * sizeof(int)); // 40
    printf("Before assignment:\n");
    for (int i = 0 ; i < count ; i++){
        printf("number-%d:%d ",i,*(ptr+i));
    }
    printf("\n");
        // assignment
    for (int i = 0 ; i < count ; i++){
        *(ptr+i) = (i+1)*10;
    }
        // check
    printf("After assignment:\n");
    for (int i = 0 ; i < count ; i++){
        printf("number-%d:%d ",i,*(ptr+i));
    }
    printf("\n");
    free(ptr);
        // check
    printf("After free:\n");
    for (int i = 0 ; i < count ; i++){
        printf("number-%d:%d ",i,*(ptr+i));
    }

    // 2. calloc() function
    /*
        1. 与malloc()类似，但是会初始化为0
        2. 语法上，第一个参数是申请的空间的个数，第二个参数是每个空间的大小
     */
    const int size = 5;
    int *arr = calloc(size,sizeof(int));
    for (int i = 0 ; i < size ; i++) {
        printf("number-%d:%d ",i,*(arr+i));
    }
    printf("\n");
    free(arr);

    // 3. realloc() function
    /*
        1. 重新分配内存空间
        2. 语法上，第一个参数是原来的指针，第二个参数是新的大小
        3. 如果新的大小比原来的小，那么多余的部分会被丢弃；如果新的大小比原来的大，那么多余的部分会被初始化为0
        4. 在reallocate之后，新的指针可能会与之前不一致（如果原指针后续的地址已经被占用）
        5. 在reallocate之后，原始的指针会自动被释放，后续释放只需要释放新的指针即可
     */
    const int size_2 = 10;
    int *p = malloc(size_2 * sizeof(int));
    for (int i = 0 ; i < size_2 ; i++) {
        *(p + i) = (i+1)*10;
    }
    printf("Address before reallocate: %p\n",p);
    int *new_p = realloc(p,20*sizeof(int));
    printf("Address after reallocate:%p\n",new_p);
    for (int i = 0 ; i < 20 ; i++) {
        printf("number-%d:%d ",i,*(new_p+i));
    }
    free(p);
    free(new_p);
}