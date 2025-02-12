/* a test of all Object created*/

#include "../header/ComplexRationnal.h"
#include "../header/Arithmetic.h"
using namespace isa;
int main ()
{
    ComplexRationnal c1,c2,c3;
    Rationnal r1,r2,r3,r4;
    Arithmetic a=Arithmetic();
    c1 = c2 = ComplexRationnal();
    r1 = r2 = r3 = r4= Rationnal();
    r1.setNumerator(1);
    r1.setDenomirator(2);
    r2.setNumerator(4);
    r2.setDenomirator(5);
    r3.setNumerator(3);
    r3.setDenomirator(4);
    r4.setNumerator(5);
    r4.setDenomirator(6);
    c1.setReal(r1);
    c1.setImaginary(r2);
    c2.setReal(r3);
    c2.setImaginary(r4);
    c3=c1.add(c2);
    c1.displayInfo();
    c2.displayInfo();
    c3.displayInfo();
    c1 = c1.minus(c3);
    c1.displayInfo();

    return(0);

}