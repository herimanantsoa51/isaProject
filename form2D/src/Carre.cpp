#include "../header/Carre.h"
#include <iostream>
using namespace f2d;
using namespace std;
Carre::Carre()
{   
    cote=0;
    cout<< "a Carre was created"<<endl;
}   
Carre::Carre(float newCote)
{
    cote=newCote;
}
Carre::Carre(int nx,int ny)
{
    setX(nx);
    setY(ny);
}
Carre::~Carre()
{
    cout<< "a Carre was deleted"<<endl;
}
void Carre::setCote(float newCote)
{
    cote=newCote;
}   
float Carre::getCote()
{
    return(cote);
}
float Carre::surface()
{
    return(cote*cote);
}
float Carre::perimetre()
{
    return(4*cote);
}
void Carre::displayInfo()
{
    displayInfoForm();
    cout << "cote = " << cote << "\n\n" << endl;
}
