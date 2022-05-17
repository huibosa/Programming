#include <stdio.h>
int main(void)
{
    int age;

    printf("type in your age: ");
    scanf("%d", &age);
    printf("You have lived for %f seconds", age * 3.156e7);
}
