#ifndef MEDECIN_H
#define MEDECIN_H
#include "Person.h"

namespace people
{
    class Medecin:public Person
    {
    private:
        int nExperienceYear;
        string specialite;
    public:
        Medecin();
        ~Medecin();
        void setSpecialite(string newSpecialite);
        string getSpecialite();
        void setNExperienceYear(int newNExperienceYear);
        int getNExperienceYear();
        void displayMedecin();
    };
}
#endif 
