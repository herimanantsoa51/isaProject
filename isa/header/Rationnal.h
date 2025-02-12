#ifndef RATIONNAL_H
#define RATIONNAL_H

namespace isa
{
    class Rationnal
    {
    private:
        int numerator,denominator;
    public:
        Rationnal();
        ~Rationnal();
        void setNumerator(int newNumerator);
        void setDenomirator(int newDenominator);
        int getNumerator();
        int getDenominator();
        float getRealValue();
        void displayInfo();
        Rationnal add(Rationnal r2);
        Rationnal minus(Rationnal r2);
        Rationnal multiply(Rationnal r2);
        Rationnal divide(Rationnal r2);

    };
} 
#endif