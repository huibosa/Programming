// Write a program that creates a structure template with two members according
// to the following criteria:

//    a. The first member is a social security number. The second member is a
//    structure with three members. Its first member contains a first name, its
//    second member contains a middle name, and its final member contains a last
//    name. Create and initialize an array of five such structures. Have the
//    program print the data in this
 
//    format:
//    Dribble, Flossie M. –– 302039823

// Only the initial letter of the middle name is printed, and a period is
// added. Neither the initial (of course) nor the period should be printed if
// the middle name member is empty.  Write a function to do the printing; pass
// the structure array to the function.

//    b. Modify part a. by passing the structure value instead of the address.


#include <stdio.h>
#define LEN 20

struct citizen
{
    int security_num;
    struct {char fname[LEN]; char middle[LEN]; char lname[LEN];};
};

void show_in_struct_name(struct citizen);

int main(void)
{
    struct citizen peoples[5]=
    {
        { 302039823, {"Dribble", "Malan", "Flossie"} },
        { 111, {"Ran", "Hao", "Hu"} },
        { 222, {"Xiang", "", "Zhong"} },
        { 333, {"Feng", "Jun", "Li"} },
        { 444, {"Long", "Tian", "Chen"} }
    };

    for (int i = 0; i < 5; i++)
        show_in_struct_name(peoples[i]);

    return 0;
}

void show_in_struct_name(struct citizen people)
{
    // Dribble, Flossie M. –– 302039823
    printf("%s, %s %c%c -- %d\n", people.fname, people.lname,
                                  *people.middle, *people.middle ? '.' : '\b',
                                  people.security_num);
}
