#include <stdio.h>

void inplaceSwap(int* x, int* y) {
  *y = *x ^ *y;
  *x = *x ^ *y;
  *y = *x ^ *y;
}

void reverseArray(int a[], int cnt) {
  int first, last;
  for (first = 0, last = cnt - 1; first < last; first++, last--) {
    inplaceSwap(&a[first], &a[last]);
  }
}

int main(void) {
  int arr1[] = {1, 2, 3, 4};
  int arr2[] = {1, 2, 3, 4, 5};

  reverseArray(arr1, 4);
  reverseArray(arr2, 5);

  for (int i = 0; i < 4; i++) {
    printf("%d ", arr1[i]);
  }
  puts("");

  for (int i = 0; i < 5; i++) {
    printf("%d ", arr2[i]);
  }
  puts("");
}
