#include "iostream"
using namespace std;

class TourGuide
{
    public:
        string name;
        int yearofexp;
        string specialization;
    TourGuide() {}
    TourGuide(string name , int yearofexp , string specialization)
    {
        this->name = name;
        this->yearofexp = yearofexp;
        this->specialization = specialization;
    }
    void display()
    {
        cout << "-----Independent Tour Guide-----" << endl;
        cout << "Name: " << name << endl;
        cout << "Experience: " << yearofexp << endl;
        cout << "Specialization: " << specialization << endl;
    }
    ~TourGuide()
    {
        cout << "Object " << name << " is being Destroyed!!" << endl;
    }
};
class TravelAgency
{
    private:
        TourGuide tg;
    public:
        int n;
        string name;
        string *tourg;
    TravelAgency(TourGuide &tg)
    {
        cout << "Enter the agency name: ";
        getline(cin , name);
        cout << "Enter the number of tour guide: ";
        cin >> n;
        tourg = new string[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the name of tour guide " << i + 1 << " : ";
            cin >> tg.name;
            cout << "Enter years of experience: ";
            cin >> tg.yearofexp;
            cout << "Enter guide's specialization: ";
            cin >> tg.specialization;
            tourg[i] = tg.name;
        }
    }
    void display()
    {
        cout << "Agency: " << name << endl;
        cout << "Tour Guides: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << ". " << tourg[i] << endl;
        }
    }
    ~TravelAgency()
    {
        delete []tourg;
        cout << "Travel Agency " << name << " Destroyed!!" << endl;
    }
};

int main()
{
    TourGuide tg;
    TravelAgency ta(tg);
    ta.display();
    cout << endl;
    TourGuide tf("Ali",5,"Hiking");
    tf.display();
    cout << endl;
}
