using namespace  std;
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