#include "iostream"
using namespace std;


class Patient
{
    private:
    int num;
    static int ID;
    public:
    string name;
    string *result;

    Patient()
    {
        cout << "Enter Patient's Name: ";
        cin >> name;
        cout << "Enter the number of recent tests: ";
        cin >> num;
        result = new string[num];
        for (int i = 0; i < num; i++)
        {
            cout << "Test Result " << i + 1 << " : ";
            cin >> result[i];
        }
        ID++;
    }
    Patient(const Patient &p1)
    {
        this->num = p1.num;
        this->name = p1.name;
        result = new string[num];
        for (int i = 0; i < num; i++)
        {
            result[i] = p1.result[i];    
        }
        ID++;
    }
    void display()
    {
        cout << "Patient ID: " << ID << endl;
        cout << "Patient Name: " << name << endl;
        cout << "Recent Test Result: " << endl;
        for (int i = 0; i < num; i++)
        {
            cout << i + 1 << ". " << result[i] << endl;
        }
        
    }
    ~Patient()
    {
        delete []result;
    }
};

int Patient :: ID = 100;

int main()
{
    Patient p1;
    cout << endl;
    p1.display();
    cout << endl;
    Patient p2;
    cout << endl;
    p2.display();
    Patient p3(p1);
    cout << endl;
    p3.display();
}
