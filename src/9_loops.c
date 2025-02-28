#include <stdio.h>

int main() {
    // C 中的循环语法与Java类似，有 for、while、do while 三种循环
    // 1. for 循环
        // 打印直角三角形
    for (int i = 0 ; i < 5 ; i++){
        for (int j = 0 ; j < i+1 ; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
        // 打印等腰三角形
    for (int i = 0 ; i < 5 ; i++) {
        // 打印空格
        for (int j = 0 ; j < 5 - i -1 ; j++) {
            printf(" ");
        }
        // 打印星号
        for (int k = 0 ; k < 2*i+1 ; k++) {
            printf("*");
        }
        printf("\n");
    }


    return 0;
}