#include <stdio.h>

#define N 3

typedef int Mat[N][N];

void ijk(Mat C, Mat A, Mat B, int n) {
  int sum;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      sum = 0;
      for (int k = 0; k < n; k++) {
        sum += A[i][k] * B[k][j];
      }
      C[i][j] = sum;
    }
  }
}

void jik(Mat C, Mat A, Mat B, int n) {
  int sum = 0;
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      sum = 0;
      for (int k = 0; k < n; k++) {
        sum += A[j][k] * B[k][i];
      }
      C[j][i] = sum;
    }
  }
}

void jki(Mat C, Mat A, Mat B, int n) {
  int r;

  for (int j = 0; j < n; j++) {
    for (int k = 0; k < n; k++) {
      r = B[k][j];
      for (int i = 0; i < n; i++) {
        C[i][j] += A[i][k] * r;
      }
    }
  }
}

void kji(Mat C, Mat A, Mat B, int n) {
  int r;

  for (int k = 0; k < n; ++k) {
    for (int j = 0; j < n; ++j) {
      r = B[k][j];
      for (int i = 0; i < n; ++i) {
        C[i][j] += A[i][k] * r;
      }
    }
  }
}

void kij(Mat C, Mat A, Mat B, int n) {
  int r;

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      r = A[i][k];
      for (int j = 0; j < n; ++j) {
        C[i][j] += r * B[k][j];
      }
    }
  }
}

void ikj(Mat C, Mat A, Mat B, int n) {
  int r;

  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < n; ++k) {
      r = A[i][k];
      for (int j = 0; j < n; ++j) {
        C[i][j] += r * B[k][j];
      }
    }
  }
}

void printMatrix(Mat A, int n) {
  printf("=================\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; ++j) {
      printf("%4d ", A[i][j]);
    }
    printf("\n");
  }
  printf("-----------------\n");
}
