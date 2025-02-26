#include "iostream"
using namespace std;

class Professor;
class University
{
    public:
        string *profname;
        string *profdept;
        int num;

    University(Professor& p)
    {
        cout << "Enter the number of Professor's: ";
        cin >> num;
        profname = new string[num];
        profdept = new string[num];
        cin.ignore();
        for (int i = 0; i < num; i++)
        {
            cout << "Professor " << i + 1 << ": \n";
            cout << "Enter Professor name: ";
            getline(cin , profname[i]);
            cout << "Enter the Professor's Department: ";
            getline(cin , profdept[i]);
        }
    }
    void display()
    {
        for (int i = 0; i < num; i++)
        {
            cout << i + 1 << ". Professor: " << profname[i] << "\nDepartment: " << profdept[i] << endl;
        }
    }
    ~University()
    {
        delete []profname;
        delete []profdept;
    }
};

class Professor
{
    private:
        string name;
        string department;
};

int main()
{
    Professor p2;
    University u1(p2);
    u1.display();
}
