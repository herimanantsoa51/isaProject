#ifndef ETABLISSEMENT_H
#define ETABLISSEMENT_H
#include "Infrastructure.h"
#include "Etudiant.h"
#include "Enseignant.h"
#include "Medecin.h"
#include <vector>
using namespace std;

namespace people
{
    class Etablissement:public Infrastructure
    {
    private:
        int nPerson;
        string adressEtab;
        string nameEtab;
        vector <Etudiant> etudiants;
        vector <Enseignant> enseignants;
        vector <Medecin> medecins;
    public:
        Etablissement();
        ~Etablissement();
        void setAdress(string newAdress);
        string getAdress();
        void setNPerson(int newNperson);
        int getNPerson();
        void setName(string newName);
        string getName();
        void addEtudiant(Etudiant newEtudiant);
        void deleteEtudiant(Etudiant delEtudiant);
        void addEnseignant(Enseignant newEnseignant);
        void deleteEnseignant(Enseignant delEnseignant);
        void addMedecin(Medecin newMedecin);
        void deleteMedecin(Medecin delMedecin);
        void displayEtablissement();
        void displayMedecins();
        void displayEtudiants();
        void displayEnseignants();
    };
}
#endif