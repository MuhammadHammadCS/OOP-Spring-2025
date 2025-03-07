#include "iostream"
using namespace std;


class Person
{
protected:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}

    void displayDetails()
    {
        cout << "----------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher : protected Person{
    protected:
    string subject;

    public:
    Teacher(string name, int age, string subject) : Person(name , age) , subject(subject){}

    void displayDetails()
    {
        Person :: displayDetails();
        cout << "Subject Expertise: " << subject << endl;
    }
};

class Researcher : protected Teacher{
    protected:
    string researchArea;

    public:
    Researcher(string name, int age, string subject , string researchArea) : Teacher(name , age , subject) , researchArea(researchArea){}

    void displayDetails()
    {
        Teacher :: displayDetails();
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Researcher{
    public:
    int publications;

    Professor(string name, int age, string subject , string researchArea , int publications) : Researcher(name , age , subject , researchArea) , publications(publications){}

    void displayDetails()
    {
        Researcher :: displayDetails();
        cout << "Publications: " << publications << endl;
        cout << "----------------------------" << endl;
    }
};

int main()
{
    Professor p("Imaad" , 32 , "Mathematics" , "Value of pie" , 12);
    p.displayDetails();
}
