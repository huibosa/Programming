// Colossus Airlines (from exercise 8) acquires a second plane (same capacity)
// and expands its service to four flights daily (Flights 102, 311, 444, and
// 519). Expand the program to handle four flights. Have a top-level menu that
// offers a choice of flights and the option to quit. Selecting a particular
// flight should then bring up a menu similar to that of exercise 8. However,
// one new item should be added: confirming a seat assignment. Also, the quit
// choice should be replaced with the choice of exiting to the top-level menu.
// Each display should indicate which flight is currently being handled. Also,
// the seat assignment display should indicate the confirmation status.


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define NLEN 30
#define LIM  12

struct seat
{
    int number;
    bool is_assigned;
    char last[NLEN];
    char first[NLEN];
};

char prompt_user(void);
void show_nb_empty(const struct seat *);
void show_list_empty(const struct seat *);
void show_alphabetical(const struct seat *);
void assign_seat(struct seat *);
void delete_seat(struct seat *);
void eatline(void);

int main(void)
{
    FILE * fp;
    struct seat flight[LIM] = {};
    int size = sizeof(struct seat);
    int count = 0;

    if ((fp = fopen("seats.dat", "a+b")) == NULL)
    {
        fputs("Error open file \"seats.dat\".\n", stderr);
        exit(EXIT_FAILURE);
    }

    while (count < LIM && fread(&flight[count++], size, 1, fp) == 1)
        continue;

    while (true)
    {
        switch (prompt_user())
        {
            case 'a':
                show_nb_empty(flight);
                break;
            case 'b':
                show_list_empty(flight);
                break;
            case 'c':
                show_alphabetical(flight);
                break;
            case 'd':
                assign_seat(flight);
                break;
            case 'e':
                delete_seat(flight);
                break;
            case 'f':
                fclose(fp);
                if ((fp = fopen("seats.dat", "w+b")) == NULL)
                {
                    fputs("Error open file \"seats.dat\".\n", stderr);
                    exit(EXIT_FAILURE);
                }
                fwrite(flight, sizeof(flight), 1, fp);
                fclose(fp);
                return 0;
            default:
                puts("Wrong input please type again");
        }
    }
    puts("bye");

    return 0;
}

char prompt_user(void)
{
    char choice;

    puts("**********************************************");
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Quit");
    puts("**********************************************");

    printf("Enter your choice: ");
    choice = getchar();

    eatline();

    return choice;
}

void show_nb_empty(const struct seat * ps)
{
    int count = 0;

    for (int i = 0; i < LIM; i++)
        if (!ps[i].is_assigned)
            count++;
    printf("There are %d seat%s empty.\n", count, count == 1 ? "" : "s");
}

void show_list_empty(const struct seat * ps)
{
    for (int i = 0; i < LIM; i++)
        printf("Seat %d: %s\n", i+1, ps[i].is_assigned ? "assigned" : "empty");
}

void show_alphabetical(const struct seat * ps)
{
    struct seat tmp[LIM];
    struct seat temp;

    for (int i = 0; i < LIM; i++)
        tmp[i] = ps[i];

    for (int i = 0; i < LIM-1; i++)
        for (int j = i; j < LIM; j++)
            if (strcmp(tmp[i].last, tmp[i].last) > 0)
            {
                temp = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = temp;
            }

    for (int i = 0; i < LIM; i++)
        printf("Seat %d: %s %s\n", tmp[i].number, tmp[i].last, tmp[i].first);
}

void assign_seat(struct seat * ps)
{
    int seat_number;

    printf("Please enter the seat number (negative to quit): ");
    while (scanf("%d", &seat_number) == 1 && seat_number >= 0 &&
                                            seat_number <= LIM)
    {
        if (ps[seat_number-1].is_assigned == true)
        {
            printf("Seat %d assigned,"
                   " please enter another number: ", seat_number);
            eatline();
            continue;
        }
        else
            ps[seat_number-1].number = seat_number;

        printf("Enter the last name: ");
        scanf("%s", ps[seat_number-1].last);
        printf("Enter the first name: ");
        scanf("%s", ps[seat_number-1].first);
        ps[seat_number-1].is_assigned = true;
        printf("Please enter the seat number (negative to quit): ");
    }

    eatline();
}

void delete_seat(struct seat * ps)
{
    int seat_number;

    printf("Enter the seat number to delete: ");
    scanf("%d", &seat_number);

    eatline();

    ps[seat_number-1].is_assigned = false;
    strcpy(ps[seat_number-1].last, "");
    strcpy(ps[seat_number-1].first, "");
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
