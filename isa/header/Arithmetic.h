#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include "Rationnal.h"
#include "ComplexRationnal.h"
#include "Complex.h"

namespace isa
{
    class Arithmetic
    {
    public:
        Arithmetic();
        ~Arithmetic();
        double add(double x,double y);
        double add(Rationnal x,double y);
        double add(double x,Rationnal y);
        Rationnal add(Rationnal x,Rationnal y);
        Rationnal add(Rationnal x,int y);
        Rationnal add(int x,Rationnal y);
        Complex add(Complex x,Complex y);
        Complex add(Complex x,double y);
        Complex add(double x,Complex y);
        Complex add(Complex x,Rationnal y);
        Complex add(Rationnal x,Complex y);
        ComplexRationnal add(ComplexRationnal x,ComplexRationnal y);
        ComplexRationnal add(ComplexRationnal x, Rationnal y);
        ComplexRationnal add(Rationnal x,ComplexRationnal y);
    };
} 
#endif
