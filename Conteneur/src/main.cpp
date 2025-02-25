 #include "../header/Registre.h"
using namespace registre;
 int main()
 {
    Person p1("Christian","Manitriniaina","Antsiranana",12);
    Person p2("Christian","herimanantsoa","Antananarivo",13);
    Person p3("Loli","Pop","Morondava",15);
    Person p4("Jessuis","Malade","Antananarivo",13);
    Person p5("demain","aujourd_hui","Toliara",13);
    Registre myRegistre("Family");
    myRegistre.addPerson(p1);
    myRegistre.addPerson(p2);
    myRegistre.addPerson(p3);
    myRegistre.addPerson(p4);
    myRegistre.addPerson(p5);
    
    myRegistre.displayRegistre();
    
    myRegistre.deletePerson(p1);

    myRegistre.displayRegistre();    
}