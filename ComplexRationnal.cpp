#include "isa.h"
#include <iostream>
using namespace isa;

ComplexRationnal::ComplexRationnal()
{
    real=Rationnal();
    imaginary=Rationnal();
}
ComplexRationnal::~ComplexRationnal()
{
    std::cout<<"a ComplexRationnal was deleted"<<endl;
}
void ComplexRationnal::setReal(Rationnal newReal)
{
    real=newReal;
}
void ComplexRationnal::setImaginary(Rationnal newImaginary)
{
    imaginary=newImaginary;
}
Rationnal  ComplexRationnal::getReal()
{
    return(real);
}
Rationnal  ComplexRationnal::getImaginary()
{
    return(imaginary);
}
ComplexRationnal ComplexRationnal::add(ComplexRationnal c2)
{
    ComplexRationnal result=ComplexRationnal();
    result.setReal(real.add(c2.getReal()));
    result.setImaginary(imaginary.add(c2.getImaginary()));
    return(result);
}
ComplexRationnal ComplexRationnal::minus(ComplexRationnal c2)
{
    ComplexRationnal result=ComplexRationnal();
    result.setReal(real.minus(c2.getReal()));
    result.setImaginary(imaginary.minus(c2.getImaginary()));
    return(result);
}
ComplexRationnal ComplexRationnal::multiply(ComplexRationnal c2)
{
    ComplexRationnal result=ComplexRationnal();
    Rationnal a,b;
    a=real.multiply(c2.getReal());
    b=imaginary.multiply(c2.getImaginary());
    result.setReal(a.minus(b));
    a=real.multiply(c2.getImaginary());
    b=imaginary.multiply(c2.getReal());
    result.setImaginary(a.add(b));

    return(result);
}
void ComplexRationnal::displayInfo()
{
    std::cout<<"-------InfoComplexRationnal-----------"<<std::endl;
    std::cout<<"Real Party:"<<std::endl;
    real.displayInfo();
    std::cout<<"Imaginary Party:"<<std::endl;
    imaginary.displayInfo();
    
}





