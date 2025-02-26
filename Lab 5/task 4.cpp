#include "iostream"
using namespace std;

class Battery
{
    private:
        int capacity;

    public:
        void setcap(int capacity)
        {
            this->capacity = capacity;
        }
        void display()
        {
            cout << "Battery Capacity: " << capacity << " mAh" << endl;
        }
};
class Smartphone
{
    private:
        Battery b;
    public:
        string name;
        int cap;
        string comapny;
        int year;
    Smartphone()
    {
        cout << "Enter name of smartphone: ";
        getline(cin , name);
        cout << "Enter Manufacturer: ";
        getline(cin , comapny);
        cout << "Enter Manufacturer year: ";
        cin >> year;
        cout << "Enter Battery Capacity: ";
        cin >> cap;
        b.setcap(cap);
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Manufacturer: " << comapny << endl;
        cout << "Manufacturer Year: " << year << endl;
        b.display();
    }
    ~Smartphone()
    {
        cout << endl;
    }
};

int main()
{
    Smartphone p;
    p.display();
}
