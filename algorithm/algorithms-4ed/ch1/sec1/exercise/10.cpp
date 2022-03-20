// What is wrong with the following code fragment

int main() {
  int * a;    // dangling pointer
  for (int i = 0; i < 10; ++i) {
    a[i] = i * i;
  }

  return 0;
}
