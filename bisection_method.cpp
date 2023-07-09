#include <iostream>
#include <cmath>

double function(double x) {
    // Define your function here
    return x * x - 4*x-10;
}

double bisection(double a, double b, double tolerance) {
    if (function(a) * function(b) >= 0) {
        std::cout << "Bisection method cannot guarantee convergence for the given interval." << std::endl;
        return 0.0;
    }

    double c = a;
    while ((b - a) >= tolerance) {
        c = (a + b) / 2;

        if (function(c) == 0.0) {
            break;
        } else if (function(c) * function(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    return c;
}

int main() {
    double a, b, tolerance;
    std::cout << "Enter the initial interval [a, b]: ";
    std::cin >> a >> b;

    std::cout << "Enter the tolerance: ";
    std::cin >> tolerance;

    double root = bisection(a, b, tolerance);

    std::cout << "Approximate root: " << root << std::endl;
    std::cout << "Function value at the approximate root: " << function(root) << std::endl;

    return 0;
}
