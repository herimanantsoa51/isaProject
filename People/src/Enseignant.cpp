#include "../header/Enseignant.h"
#include <iostream>
using namespace people;
Enseignant::Enseignant()
{
    cout  << "an Enseignant was created"<< endl;
    subjectTeached="None";
}
Enseignant::~Enseignant()
{
    cout << "an Enseignant was deleted" << endl;
}
void Enseignant::setSubjectTeached(string newSubject)
{
    subjectTeached=newSubject;
}
string Enseignant::getSubjectTeached()
{
    return(subjectTeached);
}
void Enseignant::displayEnseignant()
{   
    
    cout << "\n\n";
    displayPerson();
    cout << "Subject Teached:" << subjectTeached << endl;
}
