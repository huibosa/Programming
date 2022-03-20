// A text file holds information about a softball team. Each line has data
// arranged as follows:
//
// 4 Jessie Joybat 5 2 1 1
//
// The first item is the player’s number, conveniently in the range 0–18. The
// second item is the player’s first name, and the third is the player’s last
// name. Each name is a single word. The next item is the player’s official
// times at bat, followed by the number of hits, walks, and runs batted in
// (RBIs). The file may contain data for more than one game, so the same player
// may have more than one line of data, and there may be data for other players
// between those lines. Write a program that stores the data into an array of
// structures. The structure should have members to represent the first and
// last names, the at bats, hits, walks, and RBIs (runs batted in), and the
// batting average (to be calculated later). You can use the player number as
// an array index. The program should read to end-of-file, and it should keep
// cumulative totals for each player.
//
// The world of baseball statistics is an involved one. For example, a walk or
// reaching base on an error doesn’t count as an at-bat but could possibly
// produce an RBI. But all this program has to do is read and process the data
// file, as described next, without worrying about how realistic the data is.
//
// The simplest way for the program to proceed is to initialize the structure
// contents to zeros, read the file data into temporary variables, and then add
// them to the contents of the corresponding structure. After the program has
// finished reading the file, it should then calculate the batting average for
// each player and store it in the corresponding structure member. The batting
// average is calculated by dividing the cumulative number of hits for a player
// by the cumulative number of at-bats; it should be a floating-point
// calculation. The program should then display the cumulative data for each
// player along with a line showing the combined statistics for the entire
// team.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NLEN 20
#define LIM 20

struct player
{
    char first[NLEN];
    char last[NLEN];
    int at_bats;
    int hits;
    int walks;
    int RBIs;
    float batting_average;
};

void get_data(FILE *, int n, struct player ar[n]);
void show_data(int n, const struct player ar[n]);

int main(int argc, char * argv[])
{
    FILE * fp;
    struct player team[LIM] = {};

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s filename.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Failed to open file: %s", argv[1]);
        exit(EXIT_FAILURE);
    }

    get_data(fp, LIM, team);
    show_data(LIM, team);
    fclose(fp);

    return 0;

}

void get_data(FILE * fp, int n, struct player ar[n])
{
    char first[NLEN];
    char last[NLEN];
    int index, at_bats, hits, walks, RBIs;

    while (fscanf(fp, "%d %s %s %d %d %d %d", &index, first, last,
                                              &at_bats, &hits, &walks,
                                              &RBIs) == 7)
    {
        strcpy(ar[index].first, first);
        strcpy(ar[index].last, last);
        ar[index].at_bats += at_bats;
        ar[index].hits += hits;
        ar[index].walks += walks;
        ar[index].RBIs += RBIs;
    }

    for (int i = 0; i < n; i++)
        ar[i].batting_average = (float) ar[i].hits / ar[i].at_bats;
}


void show_data(int n, const struct player ar[n])
{
    for (int i = 0; i < n; i++)
        if (ar[i].first[0] != '\0')
            printf("%d %s %s %d %d %d %d %.2f\n",
                    i, ar[i].first, ar[i].last, ar[i].at_bats, ar[i].hits,
                    ar[i].walks, ar[i].RBIs, ar[i].batting_average);
}
