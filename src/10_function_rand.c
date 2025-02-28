#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    // 随机数函数通过两个步骤生成随机数
        // 1. 通过 srand() 函数设置随机数种子,如果不设置，那么默认为1
    srand(1);
        // 2. 通过 rand() 函数生成随机数
    for (int i = 0 ; i < 5 ; i++) {
        printf("Random number %d: %d.\n",i,rand());
    }
    // 如果随机数种子不变，那么每次运行程序生成的随机数都是一样的
    // 所以，一般会使用时间作为随机数种子
    srand(time(NULL));
    for (int i = 0 ; i < 5 ; i++){
        printf("Random number %d: %d.\n",i,rand());
    }

    // 随机数的最大值为 RAND_MAX，这个值为 2147483647
    // 如果想修改随机数的范围，可以通过取余运算
    // 例如，生成 0-9 的随机数，可以通过 rand()%10 实现
    // 生成 7-23 的随机数，可以通过 rand()%(24-7)+7 实现

    // Example ,猜大小游戏
    srand(time(NULL));
    int random_number = rand() % 100 + 1; // 1-100
    int guess_number;
    printf("Please guess a number between 1 and 100: ");
    while (1) {
        if (scanf("%d",guess_number) < random_number ) {
            printf("Too small, please guess again: ");
        }else if (scanf("%d",guess_number) > random_number) {
            printf("Too large, please guess again: ");
        }else {
            printf("Congratulations! You are right!\n");
            break;
        }
    }


    return 0;
}