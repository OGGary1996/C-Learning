# include <stdio.h>

int main() {
    // 1.创建字符串
        // 1. 通过字符数组来创建，字符串是一个副本，不会改变原数组，原数组处于字符串常量区
    char str[] = "hello world";
    printf("%s\n",str);
    char str_1[6] = {'h','e','l','l','o','\0'};// \0是字符串结束标志,需要手动为\0分配空间
    printf("%s\n", str_1);
        // 2. 通过字符数组指针来创建字符串，字符串位于字符串常量区，不可修改，read-only
    char *str_2 = "hello world";
    printf("%s\n",str_2);// 可以直接打印指针

    // 2.读取和舒服字符串
        // 1. 通过scanf读取字符串，不安全，可能会溢出，并且遇到空格就会停止
        // 此时，不能使用字符数组指针的方式初始化字符串，因为：1.字符串常量区不可修改 2.字符串常量区不可读；
        // 这只是创建了一个指针变量，但它并没有分配任何内存空间来存储字符串。
        // 指针只是一个地址，指向内存中的某个位置，但此时这个位置是未定义的。
    // char name_1[20];
    // printf("Enter user name: \n");
    // scanf("%s",name_1);
    // printf("%s,Hello!\n",name_1);

        // 2.使用fgets读取字符串，安全，可以读取整行
    char name_2[20];
    printf("Enter User name: \n");
    fgets(name_2,sizeof(name_2),stdin); // 在输入完之后按下回车，fgets会把回车也读取进来，导致输出时会有一个空行
    // fgets会把换行符也读取进来，所以需要把换行符替换为字符串结束符
    for (int i = 0 ; i < sizeof(name_2)/sizeof(name_2[0]) ; i++) {
        if (*(name_2 + i) == '\n') {
            *(name_2 + i) = '\0';
        }
    }
    printf("Hello,%s!\n",name_2);

    return 0;
}