#include <iostream>
#include "../header/Triangle.h"
using namespace f2d;
using namespace std;
Triangle::Triangle()
{
    base=0;
    hauteur=0;
    cout<< "a Triangle was created"<<endl;
}
Triangle::Triangle(float newBase,float newHauteur)
{
    base=newBase;
    hauteur=newHauteur;
}
Triangle::Triangle(int nx,int ny)
{
    setX(nx);
    setY(ny);
}
Triangle::Triangle(int nx,int ny,float newBase,float newHauteur)
{
    setX(nx);
    setY(ny);
    base=newBase;
    hauteur=newHauteur;
}
Triangle::~Triangle()
{
    cout<< "a Triangle was deleted"<<endl;
}
void Triangle::setBase(float newBase)
{
    base=newBase;
}
float Triangle::getBase()
{
    return(base);
}
void Triangle::setHauteur(float newHauteur)
{
    hauteur=newHauteur;
}
float Triangle::getHauteur()
{
    return(hauteur);
}
float Triangle::surface()
{
    return(base*hauteur/2);
}
float Triangle::perimetre()
{
    return(3*base);
}
void Triangle::displayInfo()
{
    displayInfoForm();
    cout << "base = " << base << " |hauteur = " << hauteur << "\n\n" << endl;
}   
