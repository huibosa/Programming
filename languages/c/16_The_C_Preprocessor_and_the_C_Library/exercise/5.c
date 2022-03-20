// Write a function that takes as arguments the name of an array of type int
// elements, the size of an array, and a value representing the number of
// picks. The function then should select the indicated number of items at
// random from the array and prints them. No array element is to be picked more
// than once. (This simulates picking lottery numbers or jury members.) Also,
// if your implementation has time() (discussed in Chapter 12) or a similar
// function available, use its output with srand() to initialize the rand()
// random-number generator. Write a simple program that tests the function.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 50

void arr_init(int *);
void pr_random_number(const int *, size_t, int);

int main(void)
{
    srand(time(0));
    int nums[SIZE];
    int n;

    arr_init(nums);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    pr_random_number(nums, SIZE, n);

    return 0;
}

void arr_init(int * pt)
{
    for (int i = 0; i < SIZE; i++) {
        pt[i] = ((int) rand()) % 999;
    }
}

void pr_random_number(const int * pt, size_t size, int n)
{
    bool not_picked[size];

    for (int i = 0; i < size; i++) {
        not_picked[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (not_picked[i] == false) {
            printf("%d ", pt[rand() % (size-1)]);
            not_picked[i] = true;
        }
    }
}
