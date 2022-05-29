#define N 100

int sumvec(int v[N]) {
  int sum = 0;

  for (int i = 0; i < N; i++) {
    sum += v[i];
  }

  return sum;
}
