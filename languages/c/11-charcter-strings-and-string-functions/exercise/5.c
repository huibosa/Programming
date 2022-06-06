#include <stdbool.h>
#include <stdio.h>
#define SIZE 40
char* foo(const char*, int ch);
char* s_get(char*, int);

int main(void) {
  char arr[SIZE];
  char* str = arr;
  char* find;
  char ch;

  while (true) {
    puts("Enter a string:");
    s_get(str, SIZE);
    puts("Enter the letter:");
    scanf("%c", &ch);

    find = foo(str, ch);
    puts(find);
  }

  return 0;
}

char* foo(const char* str, int ch) {
  while (*str != ch && *str != 0) str++;

  if (*str = 0) return NULL;

  return (char*)str;
}

char* foo(const char* str, int ch) {
  while (*str) {
    if (ch == *str) return (char*)str;

    str++;
  }

  return NULL;
}

char* s_get(char* str, int n) {
  char* ret_val;

  ret_val = fgets(str, n, stdin);
  if (ret_val) {
    while (*str != '\n' && *str != '\0') str++;
    if (*str == '\n')
      *str = '\0';
    else
      while (getchar() != '\n') continue;
  }

  return ret_val;
}
