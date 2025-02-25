
#include "../header/Person.h"
#include <iostream>
using namespace registre;

Person::Person()
{
   cout<<"a person was created"<<endl;
   name="none";
   prename="none";
   adress="none";
   age=0;

}
Person::Person(string newName,string newPrename,string newAdress,int newAge)
{
   cout<<"a person was created"<<endl;
   name=newName;
   prename=newPrename;
   adress=newAdress;
   age=newAge;

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
bool Person::operator==(Person other)
 {
   return(this->age==other.getAge() &&
         this->name==other.getName() &&
         this->prename==other.getPrename());
 }


 
