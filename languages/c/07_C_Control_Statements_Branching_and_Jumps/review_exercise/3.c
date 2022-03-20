#include <stdio.h>
int main(void)
{
    int num;
    int even_count = 0;
    int odd_count = 0;
    int even_average = 0;
    int odd_average = 0;

    while (scanf("%d", &num)){
        if (num == 0)
            break;
        else if (num % 2 == 0){
            even_count++;
            even_average = (even_average + num) / even_count;
        }
        else
        {
            odd_count++;
            odd_average = (odd_average + num) / odd_count;
        }
    }
        printf("\neven count: %d", even_count);
        printf("\nodd count: %d", odd_count);
        printf("\neven average %d", even_average);
        printf("\nodd average %d", odd_average);
    return 0;
}
