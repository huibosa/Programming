// sumarrayrows runs 25 times faster than sumarraycols
// for large array sizes. 

#define M 100
#define N 100

int sumarrayrows(int a[M][N]) {
  int sum = 0;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      sum += a[i][j];
    }
  }

  return sum;
}

int sumarraycols(int a[M][N]) {
  int sum = 0;

  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      sum += a[i][j];
    }
  }

  return sum;
}
