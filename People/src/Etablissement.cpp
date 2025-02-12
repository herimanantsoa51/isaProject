#include "../header/Etablissement.h"
#include <iostream>
using namespace people;
Etablissement::Etablissement()
{
    cout<<"un Etablissement cree"<<endl;
    nPerson=0;
}
Etablissement::~Etablissement()
{
    cout<<"un Etablissement supprime"<<endl;   
}
void Etablissement::setAdress(string newAdress)
{
    adressEtab=newAdress;
}
void Etablissement::setNPerson(int newNPerson)
{
    nPerson=newNPerson;
}
void Etablissement::setName(string newName)
{
    nameEtab=newName;
}
string Etablissement::getAdress()
{
    return(adressEtab);
}
int Etablissement::getNPerson()
{
    return(nPerson);
}
string Etablissement::getName()
{
    return(nameEtab);
}
void Etablissement::displayEtablissement()
{   
    int i;
    cout << "--Etablissement Info--" << endl;
    cout << "name = " << nameEtab << endl;
    cout << "adress = " << adressEtab << endl;
    displayInfrastructure();
    if (enseignants.size() > 0)
    {
        displayEnseignants();
    }
    if (medecins.size() > 0)
    {
        displayMedecins();
    }
     if (etudiants.size() > 0)
    {
        displayEtudiants();
    }
    cout << "Nombre de personne dans l'etablissement:" << nPerson << endl;
   
}
void Etablissement::addEtudiant(Etudiant newEtudiant)
{   
   
    etudiants.push_back(newEtudiant);
     nPerson++;
}
void Etablissement::deleteEtudiant(Etudiant delEtudiant)
{   
    int i,j;
    delEtudiant.displayEtudiant();
    for ( i = 0; i < etudiants.size(); i++) 
    {
        if (etudiants[i].getName() == delEtudiant.getName() && etudiants[i].getPrename() == delEtudiant.getPrename() && etudiants[i].getAge()== delEtudiant.getAge()) 
        {   
            for ( j = i; j < etudiants.size() - 1; j++) 
            {
                etudiants[j] = etudiants[j + 1];
            }
            etudiants.pop_back();
            nPerson--;
            break;
        }
    }
}

void Etablissement::addEnseignant(Enseignant newEnseignant)
{
    enseignants.push_back(newEnseignant);
    nPerson++;
}

void Etablissement::deleteEnseignant(Enseignant delEnseignant)
{
    int i, j;
    for (i = 0; i < enseignants.size(); i++) 
    {
        if (enseignants[i].getName() == delEnseignant.getName() && enseignants[i].getPrename() == delEnseignant.getPrename() && enseignants[i].getAge() == delEnseignant.getAge()) 
        {
            for (j = i; j < enseignants.size() - 1; j++) 
            {
                enseignants[j] = enseignants[j + 1];
            }
            enseignants.pop_back();
            nPerson--;
            break;
        }
    }
}
void Etablissement::addMedecin(Medecin newMedecin)
{
    medecins.push_back(newMedecin);
     nPerson++;
}
void Etablissement::deleteMedecin(Medecin delMedecin)
{
    int i, j;
    for (i = 0; i < medecins.size(); i++) 
    {
        if (medecins[i].getName() == delMedecin.getName() && medecins[i].getPrename() == delMedecin.getPrename() && medecins[i].getAge() == delMedecin.getAge()) 
        {
            for (j = i; j < medecins.size() - 1; j++) 
            {
                medecins[j] = medecins[j + 1];
            }
            medecins.pop_back();
             nPerson--;
            break;
        }
    }
}
void Etablissement::displayMedecins()
{   
    int i;
    cout << "\n---les medecins---" << medecins.size() << "---" << endl;
    for ( i = 0; i < medecins.size() ; i++)
    {
        medecins[i].displayMedecin();
    }
}
void Etablissement::displayEnseignants()
{   
    int i;
    cout << "\n---les enseignants--" << enseignants.size() << "---" << endl;
    for ( i = 0; i < enseignants.size() ; i++)
    {
        enseignants[i].displayEnseignant();
    }
}
void Etablissement::displayEtudiants()
{   
    int i;
    cout << "\n---les etudiants---" << etudiants.size() << "----" << endl;
    for ( i = 0; i < etudiants.size() ; i++)
    {
        etudiants[i].displayEtudiant();
    }
}