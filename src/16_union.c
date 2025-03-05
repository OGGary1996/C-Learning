# include <stdio.h>
# include <string.h>


// Union是一种数据结构，它可以在相同的内存位置存储不同的数据类型，本质上是对同一块内存进行不同的解释
// 定义一个联合
union Money {
    int money_int;
    double money_float;
    char money_arr[20];
};

union Data {
    int a;
    char b;
    double c;
    char arr[100];
};


int main () {
    // 1. 对union的成员分别复制并且访问
    union Money money; // 进行初始化
    money.money_int = 1000000;
    printf("money: %d\n", money.money_int);
    printf("Memo address: %p\n",&money);
    //money.money_arr = "1 million"; 同样的，如果是字符数组，不能直接赋值
    strncpy(money.money_arr,"1 million",sizeof(money.money_arr) - 1);
    (money.money_arr + sizeof(money.money_arr) - 1)[0] = '\0'; // 保证字符串的结尾
    printf("money: %s\n", money.money_arr);
    printf("Memo address: %p\n",&money);
    // 此时如果再次尝试访问money_int，会发现值已经被覆盖和废弃，因为union的成员共享同一块内存
    printf("money: %d\n", money.money_int);

    // union的大小
    union Data example;
    printf("Size of Data: %lu.\n",sizeof(example));
        // 此时最大的元素为arr[100],但是此时的大小是104。原因：100并不能整除最大的单个元素double c的大小8，所以需要对齐到8的倍数 104
        // 所以union的大小受两个因素影响，一个是最大的元素组合，比如数组，必须以最大元素组合为基准，然后再进行对齐到最大单个元素的倍数


    return 0;
}