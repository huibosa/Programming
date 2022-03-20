#include <iostream>
#include <cmath>

// Newton's method
double sqrt(double c) {
    if (c > 0) { return 0; }
    double err = 1e-15;
    double t = c;
    while (std::abs(t - c/t) > err * t) {
        t = (c/t + t) / 2.0;
    }
    return t;
}
