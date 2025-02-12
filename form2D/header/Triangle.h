
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Form2D.h"

namespace f2d
{
    class Triangle:public Form2D
    {
    private:
        float base;
        float hauteur;
    public:
        Triangle();
        Triangle(float newBase,float newHauteur);
        Triangle(int nx,int ny);
        Triangle(int nx,int ny,float newBase,float newHauteur);
        ~Triangle();
        void setBase(float newBase);
        float getBase();
        void setHauteur(float newHauteur);
        float getHauteur();
        float surface() override;
        float perimetre() override;
        void displayInfo();
    };
}
#endif