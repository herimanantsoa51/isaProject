/*this is a test of all Object and their heritage*/
#include "../header/Etablissement.h"
using namespace people;
int main()
{
    Etablissement school,hospital;
    Etudiant et[5];
    Enseignant en[3];
    Medecin me[3];
    string t;
    int i,net=5,nen=3,nme=3;
    school= Etablissement();
    hospital = Etablissement();
    // creating and intializing each member of et[5] whose we will test and to avoid wasting time
    for ( i = 0; i < net; i++)
    {
        et[i] = Etudiant();
        t = "StudentName";
        t += to_string(i+1);
        et[i].setName(t);
        t= "StudentPrename";
        t += to_string(i+1);
        et[i].setPrename(t);
        t = "StudentAdress";
        t += to_string(i+1);
        et[i].setAdress(t);
        t="StudentDegree";
        t += to_string(i+1);
        et[i].setDegree(t);
        et[i].setAge(15+i);

        school.addEtudiant(et[i]);
    }
    for ( i = 0; i < nen; i++)
    {
         en[i] = Enseignant();
        t = "EnseignantName";
        t += to_string(i+1);
        en[i].setName(t);
        t= "EnseignantPrename";
        t += to_string(i+1);
        en[i].setPrename(t);
        t = "EnseignantAdress";
        t += to_string(i+1);
        en[i].setAdress(t);
        t="SubjectTeached";
        t += to_string(i+1);
        en[i].setSubjectTeached(t);
        en[i].setAge(40+i);
        school.addEnseignant(en[i]);
    }
    for ( i = 0; i < nme; i++)
    {
         me[i] = Medecin();
        t = "MedecinName";
        t += to_string(i+1);
        me[i].setName(t);
        t= "MedecinPrename";
        t += to_string(i+1);
        me[i].setPrename(t);
        t = "MedecinAdress";
        t += to_string(i+1);
        me[i].setAdress(t);
        me[i].setNExperienceYear(10+i);
        me[i].setAge(45+i);
        school.addMedecin(me[i]);
    }
    school.setNpiece(10);
    school.displayEtablissement();
    school.deleteEtudiant(et[2]);
    school.displayEtudiants();
    
    
    
}

