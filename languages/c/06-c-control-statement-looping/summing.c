#include <stdio.h>
int main(void)
{
    long num;
    long sum = 0L;
    int status;

    printf("Pleaes enter an integer to be summed (q to quit): ");
    status = scanf("%ld", &num);

    while (status == 1) 
    {
        sum = sum + num;
        printf("Pleaes enter next integer (q to quit): ");
        status = scanf("%ld", &num);
    }

    printf("Those integers sum to %ld.\n", sum);
    
    return 0;
}
