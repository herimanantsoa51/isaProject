#include "../header/Complex.h"
#include <iostream>

using namespace isa;
using namespace std;

Complex::Complex()
{   
    real=0;
    imaginary=0;
}
Complex::~Complex()
{  
     std::cout<<"a Complex was deleted"<<endl;
}
void Complex::setReal(double newReal)
{
    real=newReal;
}
void Complex::setImaginary(double newImaginary)
{
    imaginary=newImaginary;
}
double Complex::getReal()
{
    return(real);
}
double Complex::getImaginary()
{
    return(imaginary);
}
void Complex::displayInfo()
{
    std::cout<<"----------info-------"<<std::endl;
    std::cout<<"this complex ="<<real<<"+"<<imaginary<<"i"<<std::endl;
}

Complex  Complex::add(Complex c2)
{
    Complex result=Complex();
    result.setReal(real+c2.getReal());
    result.setImaginary(real+c2.getImaginary());

    return(result);
}
Complex  Complex::minus(Complex c2)
{
    Complex result=Complex();
    result.setReal(real-c2.getReal());
    result.setImaginary(real-c2.getImaginary());
    return(result);
}
Complex  Complex::multiply(Complex c2)
{
    Complex result=Complex();
    result.setReal(real*c2.getReal()-imaginary*c2.getImaginary());
    result.setImaginary(real*c2.getImaginary()+c2.getReal()*imaginary);
    return(result);
}

