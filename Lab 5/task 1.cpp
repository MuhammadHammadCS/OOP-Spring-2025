#include "iostream"
using namespace std;


class Car 
{
    public:
        int registration_num;
        string Model;
        string owner_name;

    Car() {}
    Car(int reg, string model, string owner) 
    {
        registration_num = reg;
        Model = model;
        owner_name = owner;
    }

    Car(const Car &C) 
    {
        registration_num = C.registration_num;
        Model = C.Model;
        owner_name = "";  
    }

    void display() 
    {
        cout << "Registration Number: " << registration_num << endl;
        cout << "Model: " << Model << endl;
        cout << "Owner Name: " << owner_name << endl;
    }
};

int main() 
{
    int n;
    cout << "Enter the number of Cars: ";
    cin >> n;
    
    Car Arr[n];

    for (int i = 0; i < n; i++) {
        cout << "----Car " << i + 1 << "----" << endl;
        cout << "Enter Registration Number: ";
        int reg;
        cin >> reg;
        cout << "Enter Car Model: ";
        cin.ignore();
        string model;
        getline(cin, model);
        cout << "Enter Owner Name: ";
        string owner;
        getline(cin, owner);
        Arr[i] = Car(reg, model, owner);
    }

    int choice;
    cout << "Do you want to rent a Car? (1 = Yes, 2 = No): ";
    cin >> choice;

    if (choice == 1) 
    {
        cout << "Enter New Owner Name: ";
        cin.ignore();
        string new_name;
        getline(cin, new_name);
        
        cout << "Enter Registration Number of Car to Rent: ";
        int reg;
        cin >> reg;

        bool found = false;
        for (int i = 0; i < n; i++) 
        {
            if (Arr[i].registration_num == reg) 
            {
                Car rentedCar = Arr[i];
                rentedCar.owner_name = new_name; 
                cout << "\nCar Rented Successfully! New Details:\n";
                rentedCar.display();
                found = true;
                break;
            }
        }

        if (!found) 
        {
            cout << "Car with Registration Number " << reg << " not found.\n";
        }
    } 
    else 
    {
        cout << "No Car Rented...\n";
    }
}
