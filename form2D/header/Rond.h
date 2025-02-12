
#ifndef ROND_H
#define ROND_H
#include "Form2D.h"

namespace f2d
{
    class Rond:public Form2D
    {
    private:
        float rayon;
        float diametre;
    public:
        Rond();
        Rond(float newRayon);
        Rond(int nx,int ny);
        Rond(int nx,int ny,float newRayon);
        ~Rond();
        void setRayon(float newRayon);
        float getRayon();
        void setDiametre(float newDiametre);
        float getDiametre();
        float surface() override;
        float perimetre() override;
        void displayInfo();
    };

}


#endif
