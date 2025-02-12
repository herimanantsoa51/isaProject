#ifndef FORM2D_H
#define FORM2D_H
#include <string>
using namespace std;
namespace f2d
{
    class Form2D
    {
    private:
        int x,y;
        string color;
    public:
        
        Form2D();
        ~Form2D();
        int getX();
        int getY();
        void setColor(string Ncolor);
        string getColor();
        void setX(int nx);
        void setY(int ny);
        virtual float surface()=0; //abstract
        virtual float perimetre()=0;
        void displayInfoForm();
    };
} // namespace 2df
#endif