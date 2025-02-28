#include <stdio.h>
#include <time.h>

int main() {
    // 通过 time() 函数获取当前时间
    long long time_current = time(NULL);
    printf("Current time: %lld.\n",time_current); // 显示时间为从1970年1月1日0时0分0秒到现在的秒数

    for (int i = 0 ; i < 1000000 ; i++) {
        // do nothing
    }
    printf("The for loop's run time is %lld seconds.\n",time(NULL)-time_current);

    return 0;
}