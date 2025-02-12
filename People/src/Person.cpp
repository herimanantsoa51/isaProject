
#include "../header/Person.h"
#include <iostream>
using namespace people;
Person::Person()
{
    cout<<"a person was created"<<endl;
    name="none";
   prename="none";
   age=0;

}
Person::~Person()
{
    cout<<"a person was deleted"<<endl;
}
 string Person::getAdress()
 {
    return(adress);
 }
  string Person::getName()
 {
    return(name);
 }
  string Person::getPrename()
 {
    return(prename);
 }
  int Person::getAge()
 {
    return(age);
 }
 void Person::setAdress(string newAdress)
 {
    adress=newAdress;
 }
  void Person::setName(string newName)
 {
    name=newName;
 }
  void Person::setPrename(string newPrename)
 {
    prename=newPrename;
 }
 void Person::setAge(int newAge)
 {
    age=newAge;
 }
 void Person::displayPerson()
 {
    cout<<"name="<<name<<endl;
    cout<<"prename="<<prename<<endl;
    cout<<"adress="<<adress<<endl;
    cout<<"age="<<age<<endl;
 }


 
