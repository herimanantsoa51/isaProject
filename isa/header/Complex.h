#ifndef COMPLEX_H
#define COMPLEX_H

namespace isa
{
    class Complex
    {
    private:
        double real,imaginary;
    public:
        Complex();
        ~Complex();
        void setReal(double newReal);
        void setImaginary(double newImaginary);
        double getReal();
        double getImaginary();
        void displayInfo();
        Complex add(Complex c2);
        Complex minus(Complex c2);
        Complex multiply(Complex c2);
       
    };
} 
#endif
