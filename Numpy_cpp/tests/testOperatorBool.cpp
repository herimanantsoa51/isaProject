#include "../include/Numpy.h"
#include <initializer_list>
#include <iostream>


int main()
{
    
    np::Array a = initializer_list<initializer_list<double>>{{1.0, 2.0, 3.0},{1.0, 2.0, 3.0}};
    np::Array<bool> cond({true, false, true,false,false});
    np::Array<int> b = {4, 5, 6};
    cout << cond;

}