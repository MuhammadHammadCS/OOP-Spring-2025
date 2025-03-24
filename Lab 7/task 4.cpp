#include "iostream"
using namespace std;


class Person{
    protected:
    string name;
    string id;
    string address;
    int phoneNumber;
    string email;
    public:
    Person(string nm, string id, string add, int pn, string email) : name(nm) , id(id) , address(add) , phoneNumber(pn) , email(email){}
    virtual void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }
    virtual void updateinfo()
    {
        int choice;
        while(choice != 6)
        {
            cout << "Update:\n1.Name\n2.ID\n3.Address\n4.Phone Number\n5.Email\n6.Exit\nEnter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter New Name: ";
                cin.ignore();
                getline(cin , name);
                break;
            case 2:
                cout << "Enter New ID: ";
                cin.ignore();
                getline(cin , id);
                break;
            case 3:
                cout << "Enter New Address: ";
                cin.ignore();
                getline(cin , address);
                break;
            case 4:
                cout << "Enter New Phone number: ";
                cin >> phoneNumber;
                break;
            case 5:
                cout << "Enter New Email: ";
                cin.ignore();
                getline(cin , email);
                break;
            case 6:
                cout << "Exiting" << endl;
                break;
            default:
                cout << "Invalid Option" << endl;
                break;
            }
        }
    }
};

class student : public Person
{
    protected:
    float GPA;
    int enorllmentYear;
    
    public:
    int coursesEnrolled;
    student(string nm, string id, string add, int pn, string email, int cE, float G,int eY) : Person(nm, id, add, pn, email) , coursesEnrolled(cE) , GPA(G) , enorllmentYear(eY){}

    void displayInfo()
    {
        cout << "Student Name: " << name << endl;
        cout << "Student ID: " << id << endl;
        cout << "Student Address: " << address << endl;
        cout << "Student Phone Number: " << phoneNumber << endl;
        cout << "Student Email: " << email << endl;
        cout << "Number of Course Enrolled in: " << coursesEnrolled << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << enorllmentYear << endl;
    }
};

class Professor : public Person
{
    private:
    string department;
    string coursesTaught;
    float salary;

    public:
    Professor(string nm, string id, string add, int pn, string email, string dept, string cT , float s) : Person(nm, id, add, pn, email) , department(dept) , coursesTaught(cT) , salary(s) {}

    void displayInfo()
    {
        cout << "-------------------Prof.----------------" << endl;
        cout << "Professor's Name: " << name << endl;
        cout << "Professor's ID: " << id << endl;
        cout << "Professor's Address: " << address << endl;
        cout << "Professor's Phone Number: " << phoneNumber << endl;
        cout << "Professor's Email: " << email << endl;
        cout << "Department: " << department << endl;
        cout << "Courses Taught: " << coursesTaught << endl;
        cout << "Professor's Salary: " << salary << endl;
    }
};

class Staff : public Person
{
    private:
    string departement;
    string position;
    float salary;

    public:
    Staff(string nm, string id, string add, int pn, string email, string dept, string pos, float salary) : Person(nm, id, add, pn, email) , departement(dept) , position(pos) , salary(salary){}

    void displayInfo()
    {
        cout << "-------Staff------" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
        cout << "Deparment: " << departement << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }

};

class Course
{
    private:
    student *s1;
    int courseID;
    string courseName;
    int credits;
    string instructor;
    string schedule;
    public:
    Course(){}
    void registerStudent(student *s1)
    {
        for (int i = 0; i < s1->coursesEnrolled; i++)
        {
            cout << "Cousre " << i + 1 << ": " << endl;
            cout << "Enter Cousre ID: ";
            cin >> courseID;
            cout << "Enter Cousre Name: ";
            cin >> courseName;
            cout << "Enter Cousre credits: ";
            cin >> credits;
            cout << "Enter Cousre Instructor: ";
            cin >> instructor;
            cout << "Enter Cousre schedule: ";
            cin >> schedule;
            cout << "--------------------------" << endl;
        }
    }
};

int main()
{
    Person *P1;

    student s1("Hamza","22K-0674","13d Gulshan-e-Iqbal",924574756,"hmz@gmail.com",3,3.23,2022);
    P1 = &s1;
    P1->displayInfo();
    cout<<endl;
    Course c1;
    c1.registerStudent(&s1);
    Professor sir1("Sir Tariq","Pr22k-0051","DHA Phase 5",111223335,"tariq@nu.edu.pk","AI","Neural Network",8000);
    P1 = &sir1;
    P1->displayInfo();
    cout<<endl;
    Staff st1("Akash","S19-0094","Malir Halt",44556743,"Akash.s@nu.edu.pk","Cleaning","Head",6500);
    P1 = &st1;
    P1->displayInfo();
}
