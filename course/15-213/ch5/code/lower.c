#include <string.h>

void lower1(char* s) {
  for (size_t i = 0; i < strlen(s); i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      s[i] -= ('A' - 'a');
    }
  }
}

void lower_goto(char* s) {
  size_t i = 0;
  if (i >= strlen(s))
    goto done;
loop:
  if (s[i] >= 'A' && s[i] <= 'Z')
    s[i] -= ('A' - 'a');
  i++;
  if (i < strlen(s))
    goto loop;
done:
  return;
}

//////////////////////////////////////////////////////////////////////////////

void lower_improved(char* s) {
  size_t len = strlen(s);
  for (size_t i = 0; i < len; i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      s[i] -= ('A' - 'a');
    }
  }
}
