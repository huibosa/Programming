#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 100

void print_array(int, int *);
void randomize_array(int, int *);
void sort_array(int, int *);

int main(void)
{
    int arr[LEN];

    randomize_array(LEN, arr);
    sort_array(LEN, arr);
    print_array(LEN, arr);

    return 0;
}

void print_array(int n, int * arr)
{
    putchar('[');
    for (int i = 0; i < n; i++)
        printf("%d, ", arr[i]);
    printf("\b\b]");
}

void randomize_array(int n, int * arr)
{
    srand((unsigned int) time(0));
    for (int i = 0; i < n; i++)
        arr[i] = (rand() % 10) + 1;
}

void sort_array(int n, int * arr)
{
    int temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
