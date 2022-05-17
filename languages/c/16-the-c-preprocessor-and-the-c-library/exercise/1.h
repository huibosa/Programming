// Start developing a header file of preprocessor definitions that you want to
// use.


#define NLEN 40

extern int count;

struct student {
    char first[NLEN];
    char last[NLEN];
    int score;
};

void check_score(const struct student *);
