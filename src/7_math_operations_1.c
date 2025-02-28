#include <stdio.h>
#include <math.h>

int main() {
    //Common used Math operations
    double num_1 = 10.5;
    int num_2 = 3;
    printf("The square root of %lf is %lf.\n",num_1,sqrt(num_1)); // sqrt() -> square root
    printf("The result of %d power %lf is %lf.\n",num_2,num_1,pow(num_1,num_2)); // pow() -> power
    printf("The log of %lf is %lf.\n",num_1,log(num_1)); // log() -> natural logarithm
    printf("The log base 10 of %f is %f.\n",num_1,log10(num_1)); // log10() -> base 10 logarithm

   // Trigonometric functions , 参数与返回值都是弧度
    double num_3 = 45.0;
    printf("The sine of %lf is %lf.\n",num_3,sin(num_3*M_PI/180));
    printf("The cosine of %lf is %lf.\n",num_3,cos(num_3*M_PI/180));
    printf("The tangent of %lf is %lf.\n",num_3,tan(num_3*M_PI/180));
    printf("The arc sine of %lf is %lf.\n",num_3,asin(num_3*M_PI/180));
    printf("The arc cosine of %lf is %lf.\n",num_3,acos(num_3*M_PI/180));
    printf("The arc tangent of %lf is %lf.\n",num_3,atan(num_3*M_PI/180));
    printf("The arc tangent of %lf is %lf.\n",num_3,atan2(num_3,1.0));
        // 三角形斜边长
    printf("The hypotenuse of %lf and %d is %lf.\n",num_1,num_2,hypot(num_1,num_2));


    // 绝对值，向上取整，向下取整
    double num_4 = -10.5;
    printf("The absolute value of %lf is %lf.\n",num_4,fabs(num_4)); // fabs() -> absolute value
    printf("The ceil of %lf is %lf.\n",num_4,ceil(num_4)); // ceil() -> round up
    printf("The floor of %lf is %lf.\n",num_4,floor(num_4)); // floor() -> round down

    return 0;
}
