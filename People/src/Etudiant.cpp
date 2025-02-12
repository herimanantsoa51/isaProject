#include "../header/Etudiant.h"
#include <iostream>
using namespace people;
Etudiant::Etudiant()
{
    cout<<"an Etudiant was created"<<endl;
    degree="none";
}   
Etudiant::~Etudiant()
{
    cout<<"an Etudiant was deleted"<<endl;
}
void Etudiant::setDegree(string newDegree)
{
    degree=newDegree;
}
void Etudiant::displayEtudiant()
{   
    cout << "\n\n";
    displayPerson();
    cout<<"degree="<<degree<<endl;
}
string Etudiant::getDegree()
{
    return(degree);
}
