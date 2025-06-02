#include "../include/Numpy.h"
#include <vector>
#include <iostream>
#include <string>
#include <initializer_list>
#include <complex>
using namespace std;
int main()
{
    
    auto B = np::load_csv<int>("chri.csv");
    auto C = np::arange<float>(1,10,2);
    cout << C;
    cout << C.slice(1,4);

}