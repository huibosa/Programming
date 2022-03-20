#include <stdio.h>
#include "2.h"

void set_mode(int mode)
{
    if (mode != 0 && mode != 1)
        printf("Invalid mode specified. Mode1 %s used.\n",
                mode ? "1(US)" : "0(metric)");
}

void get_info(int mode, double * distance, double * fuel)
{
    if (mode)
    {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", distance);
        printf("Enter fuel consumed in gallons:");
        scanf("%lf", fuel);
    }
    else
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", distance);
        printf("Enter fuel comsumed in liters: ");
        scanf("%lf", fuel);
    }
}

void show_info(int mode, double distance, double fuel)
{
    if (mode)
        printf("Fuel comsumption is %.2f miles per galon.\n",
                distance / fuel);
    else
        printf("Fuel comsumption is %.2f liters per 100 km.\n",
                fuel / distance * 100);
}
