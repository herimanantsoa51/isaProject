#ifndef CARRE_H
#define CARRE_H
#include "Form2D.h"

namespace f2d
{
  class Carre:public Form2D
    {
    private:
        float cote;
    public:
        Carre();
        Carre(float newCote);
        Carre(int nx,int ny);
        ~Carre();
        void setCote(float newCote);
        float getCote();
        float surface() override;
        float perimetre() override;
        void displayInfo();
    
    };
  
}





#endif