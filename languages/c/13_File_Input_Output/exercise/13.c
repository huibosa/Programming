// Do programming Exercise 12 but use variable-length arrays (VLAs) instead
// of standard arrays.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_image_width(FILE *);
int get_image_height(FILE *);
void init(FILE *, int rows, int cols, int [rows][cols]);
void makepic(int rows, int cols, char [rows][cols], int[rows][cols]);
void showpic(FILE * fo, int rows, int cols, char [rows][cols]);

const char color[10] = {' ', '.', '\'', ':', '-',
                        '*', '=', '@', '%', '#'};

int main(int argc, char * argv[])
{
    FILE * fi, * fo;

    if (argc != 2) {
        printf("Usage: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fi = fopen(argv[1], "r")) == NULL) {
        printf("Can't open file %s for read.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fi = fopen("output.img", "w")) == NULL) {
        printf("Can't open file %s for write.\n", "output.img");
        exit(EXIT_FAILURE);
    }

    int cols = get_image_height(fi);
    int rows = get_image_width(fi);

    int digits[rows][cols];
    char chars[rows][cols];

    init(fi, rows, cols, digits);
    fclose(fi);

    makepic(rows, cols, chars, digits);
    showpic(fo, rows, cols, chars);
    fclose(fo);

    return 0;
}

int get_image_width(FILE * fp)
{
    int width = 0;

    rewind(fp);
    while (getc(fp) != '\n')
        width++;
    rewind(fp);

    return (width + 1) / 2;  // do not count spaces
}

int get_image_height(FILE * fp)
{
    int height = 0;
    char ch;

    rewind(fp);
    while ((ch = getc(fp)) != EOF)
        if (ch == '\n')
            height++;
    rewind(fp);

    return height;
}

void init(FILE * fi, int rows, int cols, int digits[rows][cols])
{
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            digits[r][c] = getc(fi) - '0';
            getc(fi);
        }
    }
}

void makepic(int rows, int cols, char chars[rows][cols], int digits[rows][cols])
{
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++)
            chars[r][c] = color[digits[r][c]];
        chars[r][cols] = '\0';
    }
}

void showpic(FILE * fo, int rows, int cols, char chars[rows][cols])
{
    for (int r = 0; r < rows; r++) {
        puts(chars[r]);
        fprintf(fo, "%s\n", chars[r]);
    }
}
