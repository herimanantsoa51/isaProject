#ifndef ETUDIANT_H
#define ETUDIANT_H
#include "Person.h"
using namespace std;

namespace people
{
    class Etudiant:public Person
    {
    private:
        string degree;
    public:
        Etudiant();
        ~Etudiant();
        void setDegree(string newDegree);
        string getDegree();
        void displayEtudiant();
    };
}
#endif 