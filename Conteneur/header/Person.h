#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
 
namespace registre
{
    class Person
    {
        private:
            string name,prename;
            string adress;
            int age;
        public:
            Person();
            ~Person();
            Person(string newName,string newPrename,string newAdress,int newAge);
            void setName(string newName);
            void setPrename(string newPrename);
            void setAdress(string newAdress);
            void setAge(int newAge);
            string getName();
            string getPrename();
            string getAdress();
            int getAge();
            bool operator==(Person other);
            void displayPerson();
    };
}
#endif 