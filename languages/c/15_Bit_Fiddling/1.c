#include <limits.h>
#include <stdio.h>

char *itobs(int, char *);
void show_bstr(const char *);

int main(void) {
  int number;
  char bin_str[CHAR_BIT * sizeof(int) + 1];

  puts("Enter integers and see them in binary");
  puts("Non-numberic inputs teminates the program.");
  while (scanf("%d", &number) == 1) {
    itobs(number, bin_str);
    printf("%d is ", number);
    show_bstr(bin_str);
    putchar('\n');
    puts("Enter the next integer");
  }
  puts("Bye");

  return 0;
}

char *itobs(int n, char *ps) {
  const static int SIZE = CHAR_BIT * sizeof(int);

  for (int i = SIZE - 1; i >= 0; i--, n >>= 1)
    ps[i] = (01 & n) + '0';
  ps[SIZE] = '\0';

  return ps;
}

void show_bstr(const char *ps) {
  int i = 1;

  while (*ps) {
    putchar(*ps++);

    if (i++ % 4 == 0)
      putchar(' ');
  }
}
