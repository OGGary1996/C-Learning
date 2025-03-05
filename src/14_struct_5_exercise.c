#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Example：有4个选项A-D，通过随机数模拟出80次投票，选出票数最高的选项，票数相同时，选出字母靠前的选项
// 1. 定义结构体类型，表示4个选项
typedef struct {
    char name;  // 选项名称
    int count;      // 选项票数
}Option;

int main() {
    // 2. 将4个选项存储到结构体数组中
    Option opts[4] = {{'A',0},{'B',0},{'C',0},{'D',0}};
    // 3. 通过随机数模拟80次投票
    srand(time(NULL));
    for (int i = 0 ; i< 80 ; i++){
        int choice = rand() % 4; // 0-3,恰好对应数组的索引
        (opts + choice)->count++; // 选项票数+1
    }
    //4. 选出票数最高的选项
    int max_count = (opts + 0)->count; // 假设第一个选项票数最高
    for (int i = 1 ; i < 4 ; i++){
        if ((opts + i)->count > max_count){
            max_count = (opts + i)->count;
        }
    }
    // 5. 找出票数最高的选项
    for (int i = 0 ; i < 4 ; i++) {
        if ((opts + i)->count == max_count){
            printf("选项%c获得最高,票数为%d\n",(opts + i)->name,(opts + i)->count);
            break;
        }
    }


    return 0;
}

