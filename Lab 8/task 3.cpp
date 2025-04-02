#include "iostream"
using namespace std;

class Teacher;
class Student{
    private:
    string name;
    char grades[3];
    public:
    Student(string name) : name(name)
    {
        cout << "Enter Student name: " << name << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Enter Grade " << i + 1 << ": ";
            cin >> grades[i];
        }
        
    }
    friend class Teacher;
    friend void calculateAverageGarde(Student s);
};

class Teacher{
    public:
    void displayResult(Student& s)
    {
        cout << "Student Name: " << s.name << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Grade " << i + 1 << " : " << s.grades[i] << endl;
        }
    }

    void updateResult(Student &s)
    {
        int Gtoupdate;
        cout << "Enter the Grade Number to Update(1,2,3): ";
        cin >> Gtoupdate;
        cout << "Enter New Grade for " << Gtoupdate << " : ";
        Gtoupdate = Gtoupdate - 1;
        cin >> s.grades[Gtoupdate];
    }
    friend void calculateAverageGarde(Student s);
};

void calculateAverageGarde(Student s)
{
    int total = 0;
    float avg;
    for (int i = 0; i < 3; i++)
    {
        if(s.grades[i] == 'A' || s.grades[i] == 'a')
        {
            total += 85;
        }
        else if(s.grades[i] == 'B' || s.grades[i] == 'b')
        {
            total += 75;
        }
        else if(s.grades[i] == 'C' || s.grades[i] == 'c')
        {
            total += 65;
        }
        else if(s.grades[i] == 'D' || s.grades[i] == 'd')
        {
            total += 55;
        }
        else
        {
            total += 30;
        }
    }
    avg = total / 3;
    if(avg > 75)
    {
        cout << "Average Grade: A" << endl; 
    }
    else if(avg >= 65 && avg < 75)
    {
        cout << "Average Grade: B" << endl;
    }
    else if(avg >= 55 && avg < 65 )
    {
        cout << "Average Grade: C" << endl;
    }
    else
    {
        cout << "Average Grade: D" << endl;
    }
}

int main()
{
    Student st("Umer");
    Teacher t;
    t.displayResult(st);
    calculateAverageGarde(st);
    t.updateResult(st);
    t.displayResult(st);
    calculateAverageGarde(st);
}
