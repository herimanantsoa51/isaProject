#include "Person.h"
#include <vector>
 
using namespace std;

namespace registre
{
    class Registre
    {
    private:
        vector<Person> members;
        string name;
    public:
        Registre();
        Registre(string name);
        ~Registre();
        void setMember(vector<Person> newMembers);
        void setName(string newName);
        string getName();
        vector<Person> getMembers();
        int getCardMembers();
        void addPerson(Person newPerson);
        void deletePerson(Person delPerson);
        Registre searchByname(string name);               //retourne un Registre contenant les Personnes qui a exactement name comme name
        Registre searchByPrename(string prename);          //retourne un Registre contenant les Personnes qui a exactement prename comme prename
        Registre searchByAge(int age);     //retourne un Registre contenant les Personnes qui a exactement age comme age
        Registre searchByAge(int ageMin,int AgeMax); //retourne un Registre contenant les Personnes qui a un age entre ageMin et Age Max
        void displayRegistre();        
    };
}

