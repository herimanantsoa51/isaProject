#include <iostream>
#include <iomanip> //for precison while we use cout to display a float or double type
#include "isa.h"
using namespace isa;
    Rationnal::Rationnal()
    {   
        numerator=0;
        denominator=1; 
    }
    Rationnal::~Rationnal()
    {
         std::cout<<"a Rationnal was deleted"<<endl;
    }
    void Rationnal::setNumerator(int newNumerator)
    {
        numerator=newNumerator;
    }
    void Rationnal::setDenomirator(int newDenominator)
    {   
        if (newDenominator==0)
        {
            std::cout<<"you entered a 0 for denominator"<<std::endl;
        }
        else
        {
            denominator=newDenominator;
        }
    }
    int Rationnal::getNumerator()
    {
        return(numerator);
    }
    int Rationnal::getDenominator()
    {
        return(denominator);
    }
    float Rationnal::getRealValue()
    {
        return((float)numerator/denominator);
    }
    void Rationnal::displayInfo()
    {
        std::cout << "-------info Rationnal----------"<<std::endl;
        std::cout<<"numerator="<<numerator<<std::endl;
        std::cout<<"denominator="<<denominator<<std::endl;
        std::cout<<std::fixed<<std::setprecision(20);
        std::cout<<"realvalue="<<getRealValue()<<std::endl;
    }
    Rationnal Rationnal::add(Rationnal r2)
    {
        Rationnal result=Rationnal();
        result.setNumerator((numerator*r2.getDenominator())+(r2.getNumerator()*denominator));
        result.setDenomirator(denominator*r2.getDenominator());

        return(result);
    }
    Rationnal Rationnal::minus(Rationnal r2)
    {
        Rationnal result=Rationnal();
        result.setNumerator((numerator*r2.getDenominator())-(r2.getNumerator()*denominator));
        result.setDenomirator(denominator*r2.getDenominator());

        return(result);
    }
    Rationnal Rationnal::multiply(Rationnal r2)
    {
        Rationnal result=Rationnal();
        result.setNumerator(numerator*r2.getNumerator());
        result.setDenomirator(denominator*r2.getDenominator());

        return(result);
    }
    Rationnal Rationnal::divide(Rationnal r2)
    {
        Rationnal result=Rationnal();
        result.setNumerator(numerator*r2.getDenominator());
        result.setDenomirator(denominator*r2.getNumerator());

        return(result);
    }




