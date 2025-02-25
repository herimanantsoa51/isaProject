#include "../header/Registre.h"
#include <iostream>
#include <algorithm>

using namespace registre;

Registre::Registre()
{
    cout<<"A Registre was created" << endl;
    name="none";
}

Registre::Registre(string name)
{
    cout<<"A Registre was created" << endl;
    this->name=name;
}
Registre::~Registre()
{
    cout << "A registre named:" << name << "was deleted" <<endl;
}
void Registre::setMember(vector<Person> newMembers)
{
    members = newMembers;
}
void Registre::setName(string newName)
{
    name=newName;
}
string Registre::getName()
{
    return(name);
}
vector<Person> Registre::getMembers()
{
    return(members);
}
int Registre::getCardMembers()
{
    return(members.size());
}
void Registre::addPerson(Person newPerson)
{
    members.push_back(newPerson);
}
void Registre::deletePerson(Person delPerson)
{
    members.erase(remove(members.begin(),members.end(),delPerson),members.end());
}
Registre Registre::searchByname(string nameToSearch)
{  
    Registre newRegistre("Search by name of " + name);
    for(Person pers:members)
    {
        if (pers.getName()==nameToSearch)
        {
            newRegistre.addPerson(pers);
        }
    }
    return(newRegistre);
}
Registre Registre::searchByPrename(string prenameToSearch)
{
    Registre newRegistre("Search by prename of " + name);
    for(Person pers:members)
    {
        if (pers.getPrename()==prenameToSearch)
        {
            newRegistre.addPerson(pers);
        }
    }
    return(newRegistre);
}
Registre Registre::searchByAge(int ageToSearch)
{
    Registre newRegistre("Search by age of " + name);
    for(Person pers:members)
    {
        if (pers.getAge()==ageToSearch)
        {
            newRegistre.addPerson(pers);
        }
    }
    return(newRegistre);
}
Registre Registre::searchByAge(int ageMin,int ageMax)
{
    Registre newRegistre;
    string ch="Search by age of between ";
    ch += ageMin;
    ch += " and ";
    ch += ageMax;
    ch += " by ";
    ch += name;
    newRegistre = Registre(ch);
    for(Person pers:members)
    {
        if (pers.getAge()>=ageMin && pers.getAge() <= ageMax)
        {
            newRegistre.addPerson(pers);
        }
    }
    return(newRegistre);
}

void Registre::displayRegistre()
{
    cout << "Info of " << name << " Registre" << endl;
    cout << "Card: " << members.size() << "\n\n\n" << endl;

    for(Person pers:members)
    {
        pers.displayPerson();
        cout<< "\n\n";
    }
}