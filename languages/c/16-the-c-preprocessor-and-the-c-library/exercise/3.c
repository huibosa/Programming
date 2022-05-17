// Polar coordinates describe a vector in terms of magnitude and the
// counterclockwise angle from the x-axis to the vector. Rectangular
// coordinates describe the same vector in terms of x and y components (see
// Figure 16.3). Write a program that reads the magnitude and angle (in
// degrees) of a vector and then displays the x and y components. The relevant
// equations are these:

// x = r cos A      y = r sin A

// To do the conversion, use a function that takes a structure containing the
// polar coordinates and returns a structure containing the rectangular
// coordinates (or use pointers to such structures, if you prefer).

#include <stdio.h>
#include <math.h>
#define DEG_TO_RAD 4*atan(1)/180

typedef struct polar_c {
    double r;
    double angle;
} Polar;

typedef struct rect_c {
    double x;
    double y;
} Rect;

Rect polar_to_gect(Polar);

int main(void)
{
    Polar polar;
    Rect rect;

    printf("Enter the magnitude: ");
    scanf("%lf", &polar.r);
    printf("Enter the angle: ");
    scanf("%lf", &polar.angle);

    rect = polar_to_gect(polar);

    printf("The x and y is %lf and %lf\n", rect.x, rect.y);

    return 0;
}

Rect polar_to_gect(Polar pl)
{
// x = r cos A      y = r sin A
    Rect rect;

    rect.x = pl.r * cos(pl.angle * DEG_TO_RAD);
    rect.y = pl.r * sin(pl.angle * DEG_TO_RAD);

    return rect;
}
