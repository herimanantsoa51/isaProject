#include "../include/Array.hpp"
#include <iostream>
#include <random>

using namespace std;
int random_int(int min, int max);
int main()
{
    auto A = np::Array<int>(10,3,2);
    int a=0,b=8;
    
    for (size_t i = 0; i < A.shape()[0]; i++)
    {
        for (size_t j = 0; j < A.shape()[1]; j++)
        {   
            for (size_t k = 0; k < A.shape()[2]; k++)
            {
                A[{i,j,k}]=random_int(0,5);
            }
        }  
    }
    auto C= A.slice(a,b);
    cout <<"A:" << endl;
    cout << A;
    A.displayShape();
    cout <<"C:" << endl;
    cout <<C;
    C.displayShape();

    return(0);
}

int random_int(int min, int max) {
    std::random_device rd;  // Générateur de nombre aléatoire basé sur le hardware
    std::mt19937 gen(rd()); // Mersenne Twister PRNG
    std::uniform_int_distribution<int> distrib(min, max); // Distribution uniforme

    return distrib(gen);
}