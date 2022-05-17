#include <limits.h>
#include <stdio.h>

char *itobs(int, char *);
void show_bstr(const char *);
int invert_end(int num, int bits);

int main(void) {
  char bin_str[CHAR_BIT * sizeof(int) + 1];
  int number;

  puts("Enter integers and see them in binary.");
  puts("Non-numberic input terminates program.");
  while (scanf("%d", &number) == 1) {
    itobs(number, bin_str);
    printf("%d is\n", number);
    show_bstr(bin_str);
    putchar('\n');

    number = invert_end(number, 4);
    printf("Inverting the last 4 bits gives\n");
    show_bstr(itobs(number, bin_str));
    putchar('\n');
  }
  puts("Bye");
}

char *itobs(int n, char *ps) {
  int size = CHAR_BIT * sizeof(int);

  for (int i = size - 1; i >= 0; i--, n >>= 1)
    ps[i] = (0x1 & n) + '0';
  ps[size] = '\0';

  return ps;
}

void show_bstr(const char *ps) {
  int ct = 1;

  while (*ps) {
    putchar(*ps++);

    if (ct++ % 4 == 0)
      putchar(' ');
  }
}

int invert_end(int num, int bits) {
  int mask = 0;
  int bitval = 1;

  while (bits-- > 0) {
    mask |= bitval;
    bitval <<= 1;
  }

  return num ^ mask;
}
