// Create a text file consisting of 20 rows of 30 integers. The integers
// should be in the range 0–9 and be separated by spaces. The file is a
// digital representation of a picture, with the values 0 through 9
// representing increasing levels of darkness. Write a program that reads
// the contents of the file into a 20-by-30 array of ints. In a crude
// approach toward converting this digital representation to a picture,
// have the program use the values in this array to initialize a 20-by-31
// array of chars, with a 0 value corresponding to a space character,
// a 1 value to the period character, and so on, with each larger number
// represented by a character that occupies more space. For example,
// you might use # to represent 9. The last character (the 31st) in each
// row should be a null character, making it an array of 20 strings. Have
// the program display the resulting picture (that is, print the strings)
// and also store the result in a text file. For example, suppose you
// start with this data:


#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30
#define LEVELS 10

void init(char [][COLS], char ch);
void MakePic(int [][COLS], char );

int main(int argc, char * argv[])
{
    const char color[LEVELS] = {' ', '.', '\'', ':', '-',
                            '*', '=', '@', '%', '#'};

    FILE * f;
    int num;
    char char_arr[ROWS][COLS+1];

    if (argc > 2) {
        fputs("Usage error", stderr);
        exit(EXIT_FAILURE);
    }
    else if (argc == 1)
        f = stdin;
    else
        if ((f = fopen(argv[1], "r")) == NULL) {
            fputs("File open error", stderr);
            exit(EXIT_FAILURE);
        }

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            fscanf(f, "%d", &num);
            char_arr[r][c] = color[num];
        }
        char_arr[r][COLS] = '\0';
    }

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++)
            putchar(char_arr[r][c]);
        putchar('\n');
    }

    fclose(f);

    return 0;
}
