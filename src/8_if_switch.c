#include <stdio.h>

int main() {
    // if statement与java中基本一致
    while(1){
        char unit;
        double temp;
        printf("The temperature is (F) or (C): ");
        scanf("%c",&unit);
        if (unit == 'C' | unit == 'c'){
            printf("The temperature is in Celsius. Please input the certain temperature: ");
            scanf("%lf",&temp);
            printf("The temperature you entered is %.2f (F).\n",temp*9/5+32);
            break;
        }else if (unit == 'F' | unit == 'f'){
            printf("The temperature is in Fahrenheit, Please input the certain temperature: ");
            scanf("%lf",&temp);
            printf("The temperature you entered is %.2f (C).\n",(temp-32)*5/9);
            break;
        }else {
            printf("Invalid input.\n");
        }
    }


    // switch语句，与java中基本一致
    float a = 10.0;
    float b = 20.0;
    printf("a ? b = ? Please make you choice: \n");
    printf("1. Add\n");
    printf("2. Sub\n");
    printf("3. Mul\n");
    printf("4. Div\n");
    int opt;
    scanf("%d",&opt);
    switch (opt) {
        case 1:
            printf("The result is %f.\n",a+b);
            break;
        case 2:
            printf("The result is %f.\n",a-b);
            break;
        case 3:
            printf("The result is %f.\n",a*b);
            break;
        case 4:
            printf("The result is %f.\n",a/b);
            break;
        default:
            printf("Invalid option.\n");
            break;
    }
    return 0;
}