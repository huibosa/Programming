// Write a program with the same behavior as described in exercise 6, but use
// an unsigned long variable to hold the font information and use the bitwise
// operators instead of bit members to manage the information.

#include <stdbool.h>
#include <stdio.h>

#define ID_MASK 0xFF
#define SIZE_MASK 0x7F00
#define ALIGNMENT_MASK 0x30000
#define BOLD 0x40000
#define ITALIC 0x80000
#define UNDERLINE 0x100000
#define LEFT 0x10000
#define CENTER 0
#define RIGHT 0x20000

struct font_struct {
  unsigned int id : 8;
  unsigned int size : 7;
  unsigned int alignment : 2;
  unsigned int bold : 1;
  unsigned int italic : 1;
  unsigned int underline : 1;
};

union Views {
  struct font_struct font0;
  unsigned long us;
};

void print_font_parameter(const unsigned long *);
char prompt_user(void);
void change_font(unsigned long *);
void change_size(unsigned long *);
void change_alignment(unsigned long *);
void toggle_bold(unsigned long *);
void toggle_italic(unsigned long *);
void toggle_underline(unsigned long *);
void eatline(void);

int main(void) {
  bool want_to_quit = false;
  union Views font = {{0, 0, 0, 0, 0, 0}};

  print_font_parameter(&font.us);
  while (!want_to_quit) {
    switch (prompt_user()) {
    case 'f':
      change_font(&font.us);
      break;
    case 's':
      change_size(&font.us);
      break;
    case 'a':
      change_alignment(&font.us);
      break;
    case 'b':
      toggle_bold(&font.us);
      break;
    case 'i':
      toggle_italic(&font.us);
      break;
    case 'u':
      toggle_underline(&font.us);
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

void print_font_parameter(const unsigned long *us) {
  printf("****************************************************\n");
  printf("%4s %4s %9s   B   I   U\n", "ID", "SIZE", "ALIGNMENT");
  printf("%4ld ", (*us & ID_MASK));
  printf("%4ld ", ((*us & SIZE_MASK) >> 8));
  switch (*us & ALIGNMENT_MASK) {
  case LEFT:
    printf("%7s", "left");
    break;
  case CENTER:
    printf("%7s", "center");
    break;
  case RIGHT:
    printf("%7s", "right");
    break;
  }
  printf("%7s", (*us & BOLD) == BOLD ? "on" : "off");
  printf("%4s", (*us & ITALIC) == ITALIC ? "on" : "off");
  printf("%4s\n", (*us & UNDERLINE) == UNDERLINE ? "on" : "off");
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

void change_font(unsigned long *us) {
  int id;

  printf("Enter font ID: ");
  scanf("%d", &id);
  eatline();

  *us &= ~ID_MASK;
  *us |= id;
  print_font_parameter(us);
}

void change_size(unsigned long *us) {
  int size;

  printf("Enter font SIZE: ");
  scanf("%d", &size);
  eatline();

  *us &= ~SIZE_MASK;
  *us |= (size << 8);
  print_font_parameter(us);
}

void change_alignment(unsigned long *us) {
  int size;

  puts("Select alignment:");
  puts("l)left   c)center    r)right");
  switch (getchar()) {
  case 'l':
    *us &= ~ALIGNMENT_MASK;
    *us |= LEFT;
    break;
  case 'r':
    *us &= ~ALIGNMENT_MASK;
    *us |= RIGHT;
    break;
  case 'c':
    *us &= ~ALIGNMENT_MASK;
    break;
  }
  eatline();

  print_font_parameter(us);
}

void toggle_bold(unsigned long *us) {
  *us ^= BOLD;
  print_font_parameter(us);
}

void toggle_italic(unsigned long *us) {
  *us ^= ITALIC;
  print_font_parameter(us);
}

void toggle_underline(unsigned long *us) {
  *us ^= UNDERLINE;
  print_font_parameter(us);
}

void eatline(void) {
  while (getchar() != '\n')
    continue;
}
