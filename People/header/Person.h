#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

namespace people
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
            void setName(string newName);
            void setPrename(string newPrename);
            void setAdress(string newAdress);
            void setAge(int newAge);
            string getName();
            string getPrename();
            string getAdress();
            int getAge();
            void displayPerson();
    };
}
#endif 