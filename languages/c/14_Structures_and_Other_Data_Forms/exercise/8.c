/*  The Colossus Airlines fleet consists of one plane with a seating capacity
    of 12. It makes one flight daily. Write a seating reservation program with
    the following features: 

     a. The program uses an array of 12 structures. Each structure should hold
        a seat identification number, a marker that indicates whether the seat
        is assigned, the last name of the seat holder, and the first name of
        the seat holder.  

     b. The program displays the following menu:
        To choose a function, enter its letter label:
        a) Show number of empty seats
        b) Show list of empty seats
        c) Show alphabetical list of seats
        d) Assign a customer to a seat assignment
        e) Delete a seat assignment
        f) Quit

    c. The program successfully executes the promises of its menu. Choices d)
       and e) require additional input, and each should enable the user to
       abort an entry.

    d. After executing a particular function, the program shows the menu again,
       except for choice f) .

    e. Data is saved in a file between runs. When the program is restarted, it
       first loads in the data, if any, from the file.              
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define NLEN 30
#define LIM  12
#define FLIGHTNUM 4

struct seat
{
    int number;
    bool is_assigned;
    char last[NLEN];
    char first[NLEN];
    int flight;
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
    struct seat tmp_seat;
    int flight_num;

    if ((fp = fopen("seats.dat", "a+b")) == NULL)
    {
        fputs("Error open file \"seats.dat\".\n", stderr);
        exit(EXIT_FAILURE);
    }

    while (fread(&tmp_seat, sizeof(struct seat), 1, fp) == 1)
        flight[tmp_seat.number - 1] = tmp_seat;

    printf("Enter the flight number: ");
    while (scanf("%d", &flight_num) == 1 && flight_num > 0 && flight_num < 5)
    {
    statements
    }
    while (true)
    {
        switch (prompt_user())
        {
            case 'a':   show_nb_empty(flight);
                        break;
            case 'b':   show_list_empty(flight);
                        break;
            case 'c':   show_alphabetical(flight);
                        break;
            case 'd':   assign_seat(flight);
                        break;
            case 'e':   delete_seat(flight);
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
