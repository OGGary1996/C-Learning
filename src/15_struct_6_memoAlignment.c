# include <stdio.h>

// 在C中，所有的数据类型的地址都会被对齐到对应数据类型的整数倍地址上，这样做是为了提高内存访问的效率
// 比如：int类型的地址会被对齐到4的整数倍地址上，double类型的地址会被对齐到8的整数倍地址上

// 结构体中，每个成员的地址都会被对齐到对应数据类型的整数倍地址上，而结构体的总大小会被对齐到结构体中最大数据类型的整数倍地址上

typedef struct {
    char a; // 0,因为后面是int类型，所以1-3会被填充为空
    int b; // 4-7
}example1; // 此时总的大小为 0-7 = 8bytes

// 调换顺序
typedef struct {
    int a; // 0-3,因为后面是char类型，而4恰好可以整除1bytes，所以不需要填充
    char b; // 4, 但是此时总的大小为5，5并不是最大元素int大小的整数倍，所以会自动填充3bytes，大小为8bytes
}example2; // 此时总的大小为 0-7 = 8bytes

// 嵌套结构体的对齐，此时内部结构体的大小需要作为整体的整数倍来考虑
typedef struct {
    char a; // 0,因为后续的内部结构体大小为8bytes，所以1-7会被填充为空
    example2 b; // 8-15: 8-11为int类型，12-15为char类型
    int c; // 16-19,此时总大小为20，20并不是最大元素example2大小的整数倍，需要填充到24bytes，所以20-23为空
}example3; // 此时总的大小为 0-23 = 24bytes
// 虽然在嵌套结构体时，内部结构体仍然需要作为一个整体来进行对齐！但是，它的大小是否会被填充，取决于编译器的优化策略和当前结构体的布局。
// 所以在此时example2的大小可能被优化到5bytes，而不是8bytes，所以example3的大小可能会变成16bytes，而不是24bytes


int main (){
    printf("Size of example1: %lu.\n",sizeof(example1));
    printf("Size of example2: %lu.\n",sizeof(example2));
    printf("Size of example3: %lu.\n",sizeof(example3));

    return 0;
}