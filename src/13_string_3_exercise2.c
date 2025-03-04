# include <stdio.h>
# include <string.h>

// 检查数组中大写字母，小写字母，数字字符的个数
int main() {
    char user_input[100];
    printf("Enter a string: \n");
    fgets(user_input,sizeof(user_input),stdin);
    if (*(user_input + strlen(user_input) -1) == '\n') {
        *(user_input + strlen(user_input) -1) = '\0';
    }
    int capital = 0;
    int small = 0;
    int digit = 0;
    for (int i = 0 ; i < strlen(user_input) ; i++) {
        if (*(user_input + i) >= 'A' && *(user_input + i) <= 'Z') {
            capital++;
        }else if (*(user_input + i) >= 'a' && *(user_input + i) <= 'z') {
            small++;
        }else if (*(user_input + i) >= '0' && *(user_input + i) <= '9') {
            digit++;
        }
    }
    printf("Capital: %d\n",capital);
    printf("Small: %d\n",small);
    printf("Digit: %d\n",digit);

    return 0;
}