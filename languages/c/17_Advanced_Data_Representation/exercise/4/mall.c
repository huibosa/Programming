#include <stdio.h>
#include <stdlib.h>     // for rand() and srand()
#include <time.h>       // for time()
#include "queue.h"

#define MIN_PER_HR 60.0

bool newcustomer(double x);     // is there a new customer?
Item customertime(long when);   // set customer parameters

int main(void) {
    Queue line1;
    Queue line2;
    Item temp;                  // new customer data
    int hours;                  // hours of simulation
    int perhour;                // average # of arrivals per hour
    long cycle, cyclelimit;     // loop counter, limit
    long turnaways = 0;         // turned away by full queue
    long customers = 0;         // joined the queue
    long served = 0;            // served during the simulation
    long sum_line1 = 0;          // cumulative line 1 length
    long sum_line2 = 0;          // cumulative line 2 length
    int wait_time1 = 0;          // time until line 1 is free
    int wait_time2 = 0;          // time until line 2 is free
    double min_per_cust;        // average time between arrivals
    long line_wait1 = 0;         // cumulative time in line 1
    long line_wait2 = 0;         // cumulative time in line 2

    InitializeQueue(&line1);
    InitializeQueue(&line2);
    srand((unsigned int) time(0));  // random initializing of rand()
    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;
    puts("Enter the average number of customers perhour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;

    for (cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(min_per_cust)) {
            if (QueueIsFull(&line1) && QueueIsFull(&line2)) {
                turnaways++;
            }
            else {
                customers++;
                temp = customertime(cycle);
                // customer choose shortest line
                if (QueueItemCount(&line1) < QueueItemCount(&line2)) {
                    Enqueue(temp, &line1);
                }
                else {
                    Enqueue(temp, &line2);
                }
            }
        }
        if (wait_time1 <= 0 && !QueueIsEmpty(&line1)) {
            Dequeue(&temp, &line1);
            wait_time1 = temp.processtime;
            line_wait1 += cycle - temp.arrive;
            served++;
        }
        if (wait_time1 > 0) {
            wait_time1--;
        }
        sum_line1 += QueueItemCount(&line1);
        if (wait_time2 <= 0 && !QueueIsEmpty(&line2)) {
            Dequeue(&temp, &line1);
            wait_time2 = temp.processtime;
            line_wait2 += cycle - temp.arrive;
            served++;
        }
        if (wait_time2 > 0) {
            wait_time2--;
        }
        sum_line1 += QueueItemCount(&line1);
    }

    if (customers > 0) {
        printf("customers accepted: %ld\n", customers);
        printf("  customers served: %ld\n", served);
        printf("       turnaways: %ld\n", turnaways);
        printf("average queue size: %.2f\n",
                (double) (sum_line1 + sum_line2) / (cyclelimit * 2));
        printf("average wait time: %.2f\n", (double) (line_wait1 + line_wait2) / (served * 2));
    }
    else {
        puts("No customer!");
    }
    EmptyTheQueue(&line1);
    EmptyTheQueue(&line2);
    puts("Bye!");

    return 0;
}

// x = average time, in minutes, between customers
// return value is true if customer shows up this minutes
bool newcustomer(double x) {
    if (rand() * x / RAND_MAX < 1) {
        return true;
    }
    else {
        return false;
    }
}

// when is the time at which the customer arrives
// function returns an Item structure with the arrival time
// set to when and the processing time set to a random value
// in the range 1 - 3
Item customertime(long when) {
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}
