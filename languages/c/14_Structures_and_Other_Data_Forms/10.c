#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SLEN 81

struct namect{
    char * fname;
    char * lname;
    int letters;
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);
void cleaup(struct namect *);
char * s_get(char * str, int n);

int main(void) {
    struct namect person;
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleaup(&person);

    return 0;
}

void getinfo(struct namect * pst) {
    char temp[SLEN];

    printf("Please enter your first name.\n");
    s_get(temp, SLEN);
    pst->fname = (char *) malloc(strlen(temp) + 1);
    strcpy(pst->fname, temp);

    printf("Please enter your last name.\n");
    s_get(temp, SLEN);
    pst->lname = (char *) malloc(strlen(temp) + 1);
    strcpy(pst->lname, temp);
}

void makeinfo(struct namect * pst) {
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect * pst) {
    printf("%s %s, your name contains %d letters.\n",
            pst->fname, pst->lname, pst->letters);
}

void cleaup(struct namect * pst) {
    free(pst->fname);
    free(pst->lname);
}

char * s_get(char * str, int n) {
    char * retval;

    retval = fgets(str, n, stdin);
    if (retval)
        str[strcspn(str, "\n")] = 0;

    fflush(stdin);

    return retval;
}
