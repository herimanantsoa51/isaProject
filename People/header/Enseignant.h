#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H
#include "Person.h"
#include <string>
using namespace std;

namespace people
{
    class Enseignant:public Person
    {
    private:
        string subjectTeached;    
    public:
        Enseignant();
        ~Enseignant();
        void setSubjectTeached(string newSubject);
        string getSubjectTeached();
        void displayEnseignant();
    };
}
#endif 