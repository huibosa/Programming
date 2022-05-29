typedef int array[2][2];

void transpose1(array dst, array src) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; i < 2; j++) {
      dst[j][i] = src[i][j];
    }
  }
}
