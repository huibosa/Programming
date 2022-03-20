// 1. Write a function that converts a binary string to a numeric value. That
// is, if you have
//
//      char * pbin = "01001001";
//
// you can pass pbin as an argument to the function and have the function
// return an int value of 25.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 29

int binstr_to_base10(const char *);

int main(void) {
  char binstr[LEN];
  char *pbin;
  int num;

  printf("Enter a binary string: ");
  scanf("%s", binstr);

  pbin = binstr;

  num = binstr_to_base10(pbin);

  printf("The base 10 numeric value is %d.\n", num);

  return 0;
}

//      char * pbin = "0011";
int binstr_to_base10(const char *pbin) {
  int base10 = 0;

  for (int i = strlen(pbin) - 1; i >= 0; i--)
    if (pbin[i] == '1')
      base10 += 1 << i;

  return base10;
}
