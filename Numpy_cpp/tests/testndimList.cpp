#include "../include/Numpy.h"
#include <iostream>

int main() 
{
    auto A = np::Array<int>
    (    
    {
        {{2,1},{2,5}},
        {{-5,6},{5,9}},
    });
    std::cout << A;
    return 0;
}
