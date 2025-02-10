#include "iostream"
using namespace std;

class TeaMug
{
    public:
    string brand;
    string color;
    int capacity;
    int CurrentfillLevel;

    void siptea()
    {
        if (CurrentfillLevel >= 2)
        {
            CurrentfillLevel -= 2;
            cout << "Sip taken... Current Filled Level: " << CurrentfillLevel << endl;
        }
        else
        {
            cout << "Not Enough Tea to Sip" << endl;
        }
    }

    void refill()
    {
        CurrentfillLevel = capacity;
        cout << "Mug Refilled to " << capacity << "ml" << endl; 
    }

    void empty()
    {
        if (CurrentfillLevel == 0)
        {
            cout << "Cup empty! It's time for a fresh cup" << endl;
        }
        else
        {
            cout << "Cup Not empty finish it for a fresh cup!!" << endl;
        }
        
    }

};

int main()
{
    TeaMug t1;
    int choice;
    cout << "Enter Brand for Tea Mug: ";
    cin.ignore();
    getline(cin , t1.brand);
    cout << "Enter the Tea Mug Color: ";
    cin.ignore();
    getline(cin , t1.color);
    cout << "Enter the Mug's Capacity: ";
    cin >> t1.capacity;
    cout << "Enter the Current Filled Level: ";
    cin >> t1.CurrentfillLevel;
    while (t1.capacity < t1.CurrentfillLevel)
    {
        cout << "Re-Enter the current filled can't be greater than capacity: ";
        cin >> t1.CurrentfillLevel;
    }
    
    while(choice != 4)
    {
        cout << "Would you like to:\n1.Sip the tea\n2.Refill the Mug\n3.Check the cup\n4.Exit\nEnter your Option: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            t1.siptea();
            break;
        case 2:
            t1.refill();
            break;
        case 3:
            t1.empty();
            break;
        case 4:
            cout << "END" << endl;
            break;    
        default:
            cout << "Invalid Option " << endl;
            break;
        }
    }
}
