#include <stdio.h>
#include <string.h>
#define SIZE 255
int main(void)
{
    char str[SIZE];
    int i = 0;

    printf("Enter a line:\n");

    do {
    scanf("%c", &str[i]);
    }while (str[i++] != '\n');

    for (int i = strlen(str); i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
}
