#include "iostream"
using namespace std;

class MarkerPen
{
    public:
    string brand;
    string color;
    int inklevel;
    bool refillability;


    void write()
    {
        if(inklevel > 0)
        {
            inklevel = inklevel - 1;
            cout << "Marker used! Ink Level Decreased. Ink Level: " << inklevel << endl;
        }
        else
        {
            cout << "Ink Level NOT sufficient" << endl;
        }
    }
    void refill()
    {
        if(inklevel < 10)
        {
            refillability = 1;
            inklevel += (10-inklevel);
            cout << "Marker requires a ink refill so refilled" << endl;
        }
        else
        {
            refillability = 0;
            cout << "Sufficient ink present in the marker" << endl;
        }
    }

};


int main()
{
    MarkerPen mk;
    cout << "-----------Marker-------------" << endl;
    cout << "Brand: ";
    cin >> mk.brand;
    cout << "Color: ";
    cin >> mk.color;
    cout << "Ink Level(1-10): ";
    cin >> mk.inklevel;
    while(mk.inklevel < 1 || mk.inklevel > 10 )
    {
        cout << "RE-enter ink level(1-10): ";
        cin >> mk.inklevel;
    }
    int choice;
    cout << endl;
    while (choice != 4)
    {
        cout << "what would you like?\n1.Write\n2.Refill\n3.Display Status\n4.Exit\nEner your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            mk.write();
            break;
        case 2:
            mk.refill();
            break;
        case 3:
            cout << "-----------------------------------------------" << endl;
            cout << "Brand: " << mk.brand << endl;
            cout << "Color: " << mk.color << endl;
            cout << "Current Ink Level: " << mk.inklevel << endl;
            if (mk.inklevel > 1)
            {
                cout << "Refillability: No" << endl;
            }
            else
            {
                cout << "Refillability: Yes" << endl;
            }
            cout << "----------------------------------------------" << endl; 
            break;
        case 4:
            cout << "Exiting....." << endl;
            break;
        default:
            cout << "Invalid Option Entered" << endl;
            break;
        } 
    }

}
