#include <stdio.h>
#define PI 3.14159
int main(void)
{
    float radius, circum, area;

    printf("What is the radius of your pizza?");
    scanf("%f", &radius);
    circum = PI * radius * 2;
    area = PI * radius * radius;
    printf("Your basic pizza parameters are as follows:\n");
    printf("circumference = %.2f, area = %.2f\n", circum, area);

    return 0;
}
