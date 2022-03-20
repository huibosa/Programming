// Design a bit-field structure that holds the following information:
//
// Font ID: A number in the range 0–255
// Font Size: A number in the range 0–127
// Alignment: A number in the range 0–2 represented the choices Left, Center,
//            and Right
// Bold: Off (0) or on (1)
// Italic: Off (0) or on (1)
// Underline: Off (0) or on (1)

#include <stdbool.h>
#include <stdio.h>

struct {
  unsigned int id : 8;
  unsigned int size : 7;
  unsigned int alignment : 2;
  unsigned int bold : 1;
  unsigned int italic : 1;
  unsigned int underline : 1;
} font;

void print_font_parameter(void);
char prompt_user(void);
void change_font(void);
void change_size(void);
void change_alignment(void);
void toggle_bold(void);
void toggle_italic(void);
void toggle_underline(void);
void eatline(void);

int main(void) {
  bool want_to_quit = false;

  print_font_parameter();
  while (!want_to_quit) {
    switch (prompt_user()) {
    case 'f':
      change_font();
      break;
    case 's':
      change_size();
      break;
    case 'a':
      change_alignment();
      break;
    case 'b':
      toggle_bold();
      break;
    case 'i':
      toggle_italic();
      break;
    case 'u':
      toggle_underline();
      break;
    case 'q':
      want_to_quit = true;
      break;
    default:
      puts("invalid input!");
      break;
    }
  }
}

void print_font_parameter(void) {
  printf("****************************************************\n");
  printf("%4s %4s %9s   B   I   U\n", "ID", "SIZE", "ALIGNMENT");
  printf("%4d ", font.id);
  printf("%4d ", font.size);
  switch (font.alignment) {
  case 1:
    printf("%7s", "left");
    break;
  case 0:
    printf("%7s", "center");
    break;
  case 2:
    printf("%7s", "right");
    break;
  }
  printf("%7s", font.bold ? "on" : "off");
  printf("%4s", font.italic ? "on" : "off");
  printf("%4s\n", font.underline ? "on" : "off");
  printf("****************************************************\n");
}

char prompt_user(void) {
  char ch;

  puts("***************************************************");
  puts("f)change font   s)change size    a)change alignment");
  puts("b)toggle bold   i)toggle italic  u)toggle underline");
  puts("q)quit");
  puts("***************************************************");
  printf("Your choice: ");
  ch = getchar();

  eatline(); /* why i need this? */

  return ch;
}

void change_font(void) {
  int id;

  printf("Enter font ID: ");
  scanf("%d", &id);
  eatline();

  font.id = id;
  print_font_parameter();
}

void change_size(void) {
  int size;

  printf("Enter font SIZE: ");
  scanf("%d", &size);
  eatline();

  font.size = size;
  print_font_parameter();
}

void change_alignment(void) {
  int size;

  puts("Select alignment:");
  puts("l)left   c)center    r)right");
  switch (getchar()) {
  case 'l':
    font.alignment = 1;
    break;
  case 'r':
    font.alignment = 2;
    break;
  case 'c':
    font.alignment = 0;
    break;
  }
  eatline();

  print_font_parameter();
}

void toggle_bold(void) {
  font.bold = ~font.bold;
  print_font_parameter();
}

void toggle_italic(void) {
  font.italic = ~font.italic;
  print_font_parameter();
}

void toggle_underline(void) {
  font.underline = ~font.underline;
  print_font_parameter();
}

void eatline(void) {
  while (getchar() != '\n')
    continue;
}
