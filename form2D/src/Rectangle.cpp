#include "../header/Rectangle.h"
#include <iostream>
using namespace std;
using namespace f2d;

Rectangle::Rectangle()
{   
    longueur=0;
    largeur=0;
    cout << "a Rectangle was created" << endl;
}
Rectangle::Rectangle(float newLongeur,float newLargeur)
{
    longueur=newLongeur;
    largeur=newLargeur;
    cout << "a Rectangle was created" << endl;
}
Rectangle::~Rectangle()
{   
    
    cout << "a Rectangle was deleted" << endl;
}
void Rectangle::setLongueur(float newLongueur)
{
    longueur=newLongueur;
}
void Rectangle::setLargeur(float newLargeur)
{
    largeur=newLargeur;
}
float Rectangle::getLargeur()
{
    return(largeur);
}
float Rectangle::getLongueur()
{
    return(longueur);
}
float Rectangle::surface()
{
    return(longueur  *  largeur);
}
float Rectangle::perimetre()
{
    return(longueur+largeur);
}
void Rectangle::displayInfo()
{
    displayInfoForm();
    cout << "longueur = "<< longueur <<" | largeur= "<< largeur << "\n\n" << endl;
}


