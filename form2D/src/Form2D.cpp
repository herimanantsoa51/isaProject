#include "../header/Form2D.h"
using namespace std;
using namespace f2d;
#include <iostream>
Form2D::Form2D()
{   
    x=0;
    y=0;
    color="none";
    cout<< "a Form2D was created"<<endl;
}
Form2D::~Form2D()
{
    cout<< "a Form2D was deleted"<<endl;
}
void Form2D::setX(int nx)
{
    x=nx;
}
void Form2D::setY(int ny)
{
    y=ny;
}
int Form2D::getX()
{
    return(x);
}
int Form2D::getY()
{
    return(y);
}
string Form2D::getColor()
{
    return(color);
}
void Form2D::setColor(string ncolor)
{
    color=ncolor;
}
void Form2D::displayInfoForm()
{
    cout << "x = " << x << " |y = " << y << " |color = " << color << endl;
}
