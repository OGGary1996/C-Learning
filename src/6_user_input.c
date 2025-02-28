#include <stdio.h>

int main() {
    // scanf() is used to read input from the user.
    // 1. decimal integer and float
    printf("Please enter your age: ");
    int age;
    scanf("%d",&age);
    printf("You are %d years old.\n",age);
    printf("Please enter your height(cm): ");
    float hight;
    scanf("%f",&hight);
    printf("You are %.2fcm tall.\n",hight);
    // 2. char or string
    // 遇到空格就停止读取
    printf("Please enter your first name: ");
    char name[20];
    scanf("%s",name);
    printf("Hello,%s! \n",name);


    // fgets() is used to read a string with spaces.
    printf("Please enter your full name: ");
    char full_name[50];
    fgets(full_name,sizeof(full_name),stdin);
    printf("Hello,%s! \n",full_name);


    // getchar() is used to read a single character.
    char degree = getchar();
    printf("You have a %c degree.\n",degree);

    return 0;
}