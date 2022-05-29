// Conflict misses in direct-mapped caches typically occur when programs
// access arrays whose sizes are a power of 2.
float dotprod(float x[8], float y[8]) {
  float sum = 0.0;

  for (int i = 0; i < 8; i++) {
    sum += x[i] * y[i];
  }

  return sum;
}
