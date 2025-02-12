#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Form2D.h"

namespace f2d
{
    class Rectangle:public Form2D
    {
    private:
        float longueur,largeur;
    public:
        Rectangle();
        ~Rectangle();
        Rectangle(float newLongeur,float newLargeur);
        void setLongueur(float newLongueur);
        void setLargeur(float newLargeur);
        float getLargeur();
        float getLongueur();
        float surface() override;
        float perimetre() override;
        void displayInfo();
    };
   
      
}




#endif