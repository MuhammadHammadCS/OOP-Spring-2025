#include "iostream"
using namespace std;

class Laptop
{
    public:
    string brand;
    string model;
    int processor;
    int ram;
    int storage;

    void turn()
    {
        char ans;
        cout << "Do you want to turn the laptop On?: ";
        cin >> ans;
        if (ans == 'Y' || ans == 'y')
        {
            cout << "Laptop Turned ON" << endl;
        }
        else if(ans == 'N' || ans == 'n')
        {
            cout << "Laptop Turned OFF" << endl;
        }
    }

    void program()
    {
        cout << "Program running.......run sucessful" << endl;
    }
    void spec()
    {
        cout << "--------------------------" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Processor: i" << processor << endl;
        cout << "Ram: " << ram << " GB" << endl;
        cout << "Storage: " << storage << " GB" << endl;
        cout << "--------------------------" << endl;
    }
};

int main()
{
    Laptop l1,l2;
    cout << "Enter Laptop Brand for Bilal: ";
    getline(cin , l1.brand);
    cout << "Enter Laptop Model for Bilal: ";
    getline(cin , l1.model);
    cout << "Enter Laptop Processor for Bilal: i";
    cin >> l1.processor;
    cout << "Enter Laptop Ram for Bilal: ";
    cin >> l1.ram;
    cout << "Enter Laptop Storage for Bilal: ";
    cin >> l1.storage;
    l1.turn();
    l1.program();
    l1.spec();
    cout << endl;
    cout << "Enter Laptop Brand for Ayesha: ";
    cin.ignore();
    getline(cin,l2.brand);
    cout << "Enter Laptop Model for Ayesha: ";
    cin.ignore();
    getline(cin , l2.model);
    cout << "Enter Laptop Processor for Ayesha: i";
    cin >> l2.processor;
    cout << "Enter Laptop Ram for Ayesha: ";
    cin >> l2.ram;
    cout << "Enter Laptop Storage for Ayesha: ";
    cin >> l2.storage;
    l2.turn();
    l2.program();
    l2.spec();
    cout << endl;
    cout << "----------Comparsion Test-------------" << endl;
    if(l1.processor > l2.processor)
    {
        cout << "Bilal has a better processor than Ayesha " << endl;
    }
    else
    {
        cout << "Ayesha has a better processor than Bilal" << endl;
    }
    if (l1.ram > l2.ram)
    {
        cout << "Bilal has a better ram than Ayesha " << endl;
    }
    else
    {
        cout << "Ayesha has a better ram than Bilal " << endl;
    }
    if (l1.storage > l2.storage)
    {
        cout << "Bilal has more storage than Ayesha " << endl;
    }
    else
    {
        cout << "Ayesha has more storage than Bilal " << endl;
    }
    
}
