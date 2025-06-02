#include "../include/Numpy.h"
#include <iostream>
#include <complex>

using namespace std;

int main()
{
    np::Array<int> A = np::ones<int>(3,3);

    complex<float> c(1,2.0);
    cout << A;
    A.fill(4);
    cout << A;
    auto B = np::zeros<complex<float>>(2,2);
    B.fill(complex<float>(1,1));
    cout << B;
}