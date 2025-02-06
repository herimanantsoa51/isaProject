#include "isa.h"
#include <iostream>
using namespace isa;
/*object to compute each objet of isa between them*/
Arithmetic::Arithmetic()
{
    std::cout<<"an Object Arithmetic was created"<<std::endl;
}
Arithmetic::~Arithmetic()
{
   std::cout<<"an Object Arithmetic was deleted"<<std::endl;
}
double Arithmetic::add(double x,double y)
{
    return(x+y);
}
double Arithmetic::add(Rationnal x,double y)
{
    return(x.getRealValue()+y);
}
double Arithmetic::add(double x,Rationnal y)
{
    return(y.getRealValue()+x);
}
Rationnal Arithmetic::add(Rationnal x,Rationnal y)
{
    return(x.add(y));
}
Rationnal Arithmetic::add(Rationnal x, int y)
{
    x.setDenomirator(x.getNumerator()+y*x.getDenominator());
    return(x);
}
Rationnal Arithmetic::add(int x,Rationnal y)
{
     y.setDenomirator(y.getNumerator()+x*y.getDenominator());
    return(y);
}
Complex Arithmetic::add(Complex x,Complex y)
{
    return(x.add(y));
}
Complex Arithmetic::add(Complex x,double y)
{   
    x.setReal(x.getReal()+y);
    return(x);
}
Complex Arithmetic::add(double x,Complex y)
{   
    y.setReal(y.getReal()+x);
    return(y);
}
Complex Arithmetic::add(Complex x,Rationnal y)
{
    x.setReal(add(x.getReal(),y));
    return(x);
}
Complex Arithmetic::add(Rationnal x,Complex y)
{
    y.setReal(add(y.getReal(),x));
    return(y);
}
ComplexRationnal Arithmetic::add(ComplexRationnal x,ComplexRationnal y)
{
    return(x.add(y));
}
ComplexRationnal Arithmetic::add(ComplexRationnal x,Rationnal y)
{
    x.setReal(y.add(x.getReal()));
    return(x);
}
ComplexRationnal Arithmetic::add(Rationnal x,ComplexRationnal y)
{
    y.setReal(x.add(y.getReal()));
    return(y);
}


