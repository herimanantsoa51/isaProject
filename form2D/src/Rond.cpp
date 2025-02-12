#include <iostream>
#include "../header/Rond.h"
using namespace f2d;
using namespace std;
Rond::Rond()
{
    rayon=0;
    diametre=0;
    cout<< "a Rond was created"<<endl;
}
Rond::Rond(float newRayon)
{
    rayon=newRayon;
    diametre=2*rayon;
}
Rond::Rond(int nx,int ny)
{
    setX(nx);
    setY(ny);
}   
Rond::Rond(int nx,int ny,float newRayon)
{
    setX(nx);
    setY(ny);
    rayon=newRayon;
    diametre=2*rayon;
}
Rond::~Rond()
{
    cout<< "a Rond was deleted"<<endl;
}
void Rond::setRayon(float newRayon)
{
    rayon=newRayon;
    diametre=2*rayon;
}
float Rond::getRayon()
{
    return(rayon);
}
void Rond::setDiametre(float newDiametre)
{
    diametre=newDiametre;
    rayon=diametre/2;
}
float Rond::getDiametre()
{
    return(diametre);
}
float Rond::surface()
{
    return(3.14159*rayon*rayon);
}
float Rond::perimetre()
{
    return(2*3.14159*rayon);
}
void Rond::displayInfo()
{
    displayInfoForm();
    cout << "rayon = " << rayon << " |diametre = " << diametre << "\n\n" << endl;
}

