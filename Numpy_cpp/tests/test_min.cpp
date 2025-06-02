#include "../include/Numpy.h"
#include <iostream>

int main() {
    np::Array<double> a(5);
    a[0] = 1.0;
    a[1] = 2.0;
    a[2] = 2.0;
    a[3] = 3.0;
    a[4] = 4.0;

    std::cout << "mean: " << np::mean(a) << std::endl;
    std::cout << "min: " << np::min(a) << std::endl;
    std::cout << "max: " << np::max(a) << std::endl;

    np::Array<double> b = np::cos(a);
    std::cout << "cos:\n" << b;

    np::Array<double> u = np::unique(a);
    std::cout << "unique:\n" << u;

    return 0;
}
