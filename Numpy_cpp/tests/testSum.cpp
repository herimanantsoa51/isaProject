#include "../include/Numpy.h"
#include <iostream>
#include <initializer_list>

int main() 
{
    auto a = np::Array(initializer_list<initializer_list<initializer_list<double>>>{
                    { 
                       {1, 2, 3}, 
                       {10, 5, -6},
                       {1, 2, 3} 
                       
                    },
                    {
                       {2, 5, 3},
                       {1, -5, 36},
                       {2, 5, 3} 
                    }
                  });
   auto A = np::ones<int>(3,4);
   auto B = np::ones<int>(4,3);
   std::cout << dot(A,B);
   std::cout << np::transpose(A);
    return 0;
}