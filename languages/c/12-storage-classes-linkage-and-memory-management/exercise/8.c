#include <stdio.h>
#include <stdlib.h>

int * make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void)
{
    int * ptr;
    int size, value;

    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d", &value);

        ptr = make_array(size, value);

        if (ptr)
        {
            show_array(ptr, size);
            free(ptr);
        }
        printf("Enter the number of elements (< 1 to quit): ");
    }
    printf("Done.\n");
    return 0;
}

int * make_array(int elem, int val)
{

    int * pt = (int *) malloc(elem * sizeof(int));
    for (int i = 0; i < elem; i++)
        pt[i] = val;

    return pt;
}

void show_array(const int ar[], int n)
{
    putchar('[');
    for (int i = 0; i < n; i++)
        printf("%d,%s", ar[i], i%8==7? "\n":"  ");
    printf("\b\b\b]\n");
}
