#include <stdio.h>
#define SIZE 4
void show_array(int size, double arr[size]);
void sum_arr(int size,
               double target[size],
               const double source1[size],
               const double source2[size]);
int main(void)
{
    double arr1[SIZE] = {2,4,5,8};
    double arr2[SIZE] = {1,0,4,6};
    double arr3[SIZE];

    sum_arr(SIZE, arr3, arr1, arr2);
    show_array(SIZE, arr3);

    return 0;

}

void sum_arr(int size,
               double target[size],
               const double source1[size],
               const double source2[size])
{
    for (int i = 0; i < size; i++){
        target[i] = source1[i] + source2[i];
    }

}

void show_array(int size, double arr[size])
{
    printf("{");
    for (int i = 0; i < size; i ++)
        printf("%.1lf, ", arr[i]);
    printf("\b\b}\n");
}
