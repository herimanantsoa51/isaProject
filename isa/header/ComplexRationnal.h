#ifndef COMPLEXRATIONNAL_H
#define COMPLEXRATIONNAL_H
#include "Rationnal.h"
namespace isa
{
     class ComplexRationnal
    {
    private:
        Rationnal real,imaginary;
    public:
        ComplexRationnal();
        ~ComplexRationnal();
        void setReal(Rationnal newReal);
        void setImaginary(Rationnal newImaginary);
        Rationnal getReal();
        Rationnal getImaginary();
        ComplexRationnal add(ComplexRationnal c2);
        ComplexRationnal minus(ComplexRationnal c2);
        ComplexRationnal multiply(ComplexRationnal c2);
        void displayInfo();
        
    };
}
#endif