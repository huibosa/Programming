#include <stdio.h>
int main(void)
{
    float height;
    char name[40];

    printf("Please type your height and name.\n");
    scanf("%f %s", &height, name);
    printf("%s, you are %.3f feet tall\n", name, height);

    return 0;
}
