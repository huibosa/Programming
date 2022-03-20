#include <stdio.h>
#include <stdbool.h>
double power(int n, int p);

int main(void)
{
    int n, p, result;

    printf("Enter two numbers (q to quit): ");
    while (scanf("%d%d", &n, &p)) {
        while (getchar() != '\n')
            continue;

        result = power(n, p);

        if (result)
            printf("%d to the %d power is %.4lf\n",
                    n, p, power(n, p));
        else
            printf("Wrong input.\n");
        printf("Enter next two number (q to quit): ");
    }

    return 0;

}

double power(int n, int p)
{
    if (p - 1 > 0) {
        return n * power(n, p - 1);
    } else if (p - 1 == 0){
        return n;
    } else if (p == 0) {
        if (n == 0)
            return false;
        else
            return 1;
    } else {
        if (n != 0) {
            p = -p;
            return 1 / (n * power(n, p - 1));
        }
        else 
            return false;
    }
}
