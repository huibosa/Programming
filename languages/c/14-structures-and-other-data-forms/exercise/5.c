// Write a program that fits the following recipe:
//
//   a. Externally define a name structure template with two members: a
//      string to hold the first name and a string to hold the second name.
//   b. Externally define a student structure template with three members: a
//      name structure, a grade array to hold three floating-point scores, and
//      a variable to hold the average of those three scores.
//   c. Have the main() function declare an array of CSIZE (with CSIZE = 4 )
//      student structures and initialize the name portions to names of your
//      choice. Use functions to perform the tasks described in parts d., e.,
//      f., and g.
//   d. Interactively acquire scores for each student by prompting the user
//      with a student name and a request for scores. Place the scores in the
//      grade array portion of the appropriate structure. The required looping
//      can be done in main() or in the function, as you prefer.
//   e. Calculate the average score value for each structure and assign it to
//      the proper member.  f. Print the information in each structure.
//   g. Print the class average for each of the numeric structure members.


#include <stdio.h>
#define LEN 20
#define CSIZE 4
#define SUBNUM 3

struct name
{
    char fname[LEN];
    char lname[LEN];
};

struct student
{
    struct name handle;
    double grade[3];
    double average;
};

void prompt_score(struct student *, int);
void get_average(struct student *, int);
void show_info(const struct student *, int);
void show_class_average(const struct student *, int);

int main(void)
{
    struct student class[CSIZE] =
    {
        {"Hua", "Li"},
        {"Ming", "Xiao"},
        {"Lei", "Hong"},
        {"Meimei", "Han"}
    };

    prompt_score(class, CSIZE);
    get_average(class, CSIZE);
    show_info(class, CSIZE);
    show_class_average(class, CSIZE);

    return 0;
}

void prompt_score(struct student ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Please enter the name for %s %s.\n", ar[i].handle.fname,
                                                     ar[i].handle.lname);
        for (int k = 0; k < SUBNUM; k++)
        {
            printf("Score of subject %d: ", k+1);
            while (scanf("%lf", &ar[i].grade[k]) != 1)
            {
                scanf("%*s");
                puts("Please use numeric input.");
            }
        }
    }
}

void get_average(struct student ar[], int n)
{
    double tot;

    for (int i = 0; i < n; i++)
    {
        tot = 0.0;

        for (int k = 0; k < SUBNUM; k++)
            tot += ar[i].grade[k];

        ar[i].average = tot / SUBNUM;
    }
}

void show_info(const struct student ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s %s: ", ar[i].handle.fname, ar[i].handle.lname);
        for (int k = 0; k < SUBNUM; k++)
            printf("%6.1f ", ar[i].grade[k]);
        printf(" Average: %5.2f.\n", ar[i].average);
    }
}

void show_class_average(const struct student ar[], int n)
{
    double sum;

    for (int i = 0; i < SUBNUM; i++)
    {
        sum = 0.0;
        for (int k = 0; k < n; k++)
            sum += ar[k].grade[i];
        printf("Subject %d: %f\n", i+1, sum/SUBNUM);
    }
}
