#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIM 10
#define LEN 100

void print_array_stat(int n, const int arr[n]);
void randomize_array(unsigned seed, int n, int arr[n]);

int main(void)
{
    int arr[LIM][LEN];

    for (int i = 0; i < LIM; i++)
        randomize_array(i, LEN, arr[i]);

    printf("Seed |");
    for (int i = 1; i < LIM+1; i++)
        printf("#%-4d", i);

    printf("\n     |------------------------------------------------\n");

    for (int i = 0; i < LIM; i++)
    {
        printf("  %d  |", i);
        print_array_stat(LIM, arr[i]);
    }
}

void randomize_array(unsigned seed, int n, int arr[n])
{
    srand(seed);
    for (int i = 0; i < n; i++)
        arr[i] = (rand() % 10) + 1;
}

void print_array_stat(int n, const int arr[n])
{
    int count[LIM+1] = {0};

    for (int i = 0; i < n; i++)
        ++count[arr[i]];

    for (int i = 1; i < LIM+1; i++)
        printf("%-5d", count[i]);

    printf("\b\n");
}
