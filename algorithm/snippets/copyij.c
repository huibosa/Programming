#include <stdio.h>
#include <time.h>

void copyij(int src[500][500], int dst[500][500]);
void copyji(int src[500][500], int dst[500][500]);

int main(void) {
  int src[500][500];
  int dst[500][500];
  double start;
  double end;

  for (int i = 0; i < 500; ++i) {
    for (int j = 0; j < 500; ++j) {
      src[i][j] = 2*j;
    }
  }
  
  for (int i = 0; i < 500; ++i) {
    for (int j = 0; j < 500; ++j) {
      dst[i][j] = i+1;
    }
  }
  
  start = clock();
  for (int i = 0; i < 1000; ++i) {
    copyij(src, dst);
  }
  end = clock();
  printf("copyij: %lf\n", (double) (end - start) / CLOCKS_PER_SEC);
  
  start = clock();
  for (int i = 0; i < 1000; ++i) {
    copyji(src, dst);
  }
  end = clock();
  printf("copyji: %lf\n", (double) (end - start) / CLOCKS_PER_SEC);

  return 0;
}

void copyij(int src[500][500], int dst[500][500]) {
  for (int i = 0; i < 500; ++i) {
    for (int j = 0; j < 500; ++j) {
      dst[i][j] = src[i][j];
    }
  }
}

void copyji(int src[500][500], int dst[500][500]) {
  for (int j = 0; j < 500; ++j) {
    for (int i = 0; i < 500; ++i) {
      dst[i][j] = src[i][j];
    }
  }
}
