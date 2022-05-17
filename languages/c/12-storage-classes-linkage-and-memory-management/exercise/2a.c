#include <stdio.h>
#include "2.h"

static int mode;
static double distance;
static double fuel;

void set_mode(int m)
{
    if (m != 0 && m != 1)
        printf("Invalid mode specified. Mode1 %s used.\n",
                mode ? "1(US)" : "0(metric)");
    else
        mode = m;
}

void get_info()
{
    if (mode)
    {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in gallons:");
        scanf("%lf", &fuel);
    }
    else
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", &distance);
        printf("Enter fuel comsumed in liters: ");
        scanf("%lf", &fuel);
    }
}

void show_info()
{
    if (mode)
        printf("Fuel comsumption is %.2f miles per galon.\n",
                distance / fuel);
    else
        printf("Fuel comsumption is %.2f liters per 100 km.\n",
                fuel / distance * 100);
}
