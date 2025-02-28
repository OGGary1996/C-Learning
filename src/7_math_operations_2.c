#include <stdio.h>
#include <math.h>

int main() {
    // calculate radians to degrees
    printf("Please type in the radians you want to convert to degrees: ");
    float radians;
    scanf("%f",&radians);
    float degrees = radians * 180 / M_PI;
    printf("The dgrees of %f radians is %f.\n",radians,degrees);

    // calculate the hypotenuse of a right triangle
    printf("Pleas type in the length of the first side of the right triangle: ");
    float side_1, side_2;
    scanf("%f",&side_1);
    printf("Please type in the length of the second side of the right triangle: ");
    scanf("%f",&side_2);
    float hypotenuse = hypot(side_1,side_2);
    printf("The hypotenuse of this triangle is %.2f.\n",hypotenuse);

    return 0;
}
