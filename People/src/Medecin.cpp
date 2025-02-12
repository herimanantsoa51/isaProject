#include "../header/Medecin.h"
#include <iostream>
using namespace std;
using namespace people;
Medecin::Medecin()
{
    cout<<"a medecin was created"<<endl;
    nExperienceYear = 0;
}   
Medecin::~Medecin()
{
    cout<<"a medecin was deleted"<<endl;
}   
void Medecin::setNExperienceYear(int newNExperienceYear)
{
    nExperienceYear=newNExperienceYear;
}   
int Medecin::getNExperienceYear()
{
    return(nExperienceYear);
}
void Medecin::displayMedecin()
{   
    cout << "\n\n";
    displayPerson();
    cout<<"nExperienceYear="<<nExperienceYear<<endl;
}   
void Medecin::setSpecialite(string newSpecialite)
{
    specialite=newSpecialite;
}
string Medecin::getSpecialite()
{
    return(specialite);
}