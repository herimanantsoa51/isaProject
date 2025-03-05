#include  "../include/Matrice.h"
using namespace isa;
int main()
{
    Matrice M1(2,2);
    Matrice M2(2,2);
    M1.setComponents({{1,1},
                    {3,1}});
    M2.setComponents({{0,2},
                    {1,1}});
    M1.display();
    M2.display();
    Matrice M3 = M1 * M2;
    M3.display();
    M3 = M3 ^ 3;
    M3.display();
    return 0;
}