#include <stdio.h>
#include <string.h>

#define NLEN 30

struct namect {
    char fname[NLEN];
    char lname[NLEN];
    int letters;
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(struct namect *);
char * s_get(char * st, int n);

int main(void) {
    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);

    return 0;
}

void getinfo(struct namect * pst) {
    printf("Please enter your first name.\n");
    s_get(pst->fname, NLEN);
    printf("Please enter your last name.\n");
    s_get(pst->lname, NLEN);
}

void makeinfo(struct namect * pst) {
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(struct namect * pst) {
    printf("%s %s, your name contains %d letters.\n",
            pst->fname, pst->lname, pst->letters);
}

char * s_get(char * st, int n) {
    char * retval;

    retval = fgets(st, NLEN, stdin);

    if (retval)
        st[strcspn(st, "\n")] = 0;

    fflush(stdin);

    return retval;
}
