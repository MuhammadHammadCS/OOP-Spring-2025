#include "iostream"
using namespace std;

class Vehicle 
{
public:
    string *Model;
    int *RPD;
    string *Eligibility;
    int count;

    Vehicle() 
    {
        cout << "Enter Number of Cars Available: ";
        cin >> count;
        cin.ignore(); 

        Model = new string[count];
        RPD = new int[count];
        Eligibility = new string[count];

        for (int i = 0; i < count; i++) 
        {
            cout << "Enter Model: ";
            cin >> Model[i];
            cout << "Enter Rental Price: ";
            cin >> RPD[i];
            cin.ignore(); 
            cout << "Enter Eligibility: ";
            getline(cin, Eligibility[i]);
            cout << endl;
        }
    }

    ~Vehicle() 
    {
        delete[] Model;
        delete[] RPD;
        delete[] Eligibility;
    }
};

class User 
{
private:
    static int Usercount;

public:
    int UserID;
    string Name;
    int Age;
    string LicenseType;
    int Contact;

    User() 
    {
        Usercount++;
    }

    void registerUser() 
    {
        cout << "Enter the User ID: ";
        cin >> UserID;
        cin.ignore();
        cout << "Enter the User Name: ";
        getline(cin, Name);
        cout << "Enter User Age: ";
        cin >> Age;
        cin.ignore();
        cout << "Enter User License Type: ";
        getline(cin, LicenseType);
        cout << "Enter Contact Number: ";
        cin >> Contact;
    }

    void update() 
    {
        int choice;
        while (choice != 4) 
        {
            cout << "\n1. Update Name\n2. Update Age\n3. Update License Type\n4. Exit\nEnter your choice: ";
            cin >> choice;
            cin.ignore();
            switch (choice) 
            {
                case 1:
                    cout << "Enter New Name: ";
                    getline(cin, Name);
                    cout << "Name Updated Successfully\n";
                    break;
                case 2:
                    cout << "Enter New Age: ";
                    cin >> Age;
                    cout << "Age Updated Successfully\n";
                    break;
                case 3:
                    cout << "Enter New License Type: ";
                    getline(cin, LicenseType);
                    cout << "License Type Updated Successfully\n";
                    break;
                case 4:
                    cout << "Update Ended.\n";
                    break;
                default:
                    cout << "Invalid Choice\n";
            }
        }
    }

    void rent(Vehicle &Vc) 
    {
        cout << "\nDisplaying available cars according to eligibility:\n";
        bool found = false;

        for (int j = 0; j < Vc.count; j++) 
        {
            if (Vc.Eligibility[j] == LicenseType) 
            {
                found = true;
                cout << "Car " << j + 1 << endl;
                cout << "Model: " << Vc.Model[j] << endl;
                cout << "Rental price per day: " << Vc.RPD[j] << endl;
                cout << "Eligibility: " << Vc.Eligibility[j] << endl;
            }
        }

        if (!found) 
        {
            cout << "No cars available for your license type.\n";
            return;
        }
        string vmodel;
        cout << "Enter the Vehicle to rent: ";
        cin >> vmodel;
        found = false;
        int vpos;
        for (int i = 0; i < Vc.count; i++) 
        {
            if (vmodel == Vc.Model[i]) 
            {
                found = true;
                vpos = i;
                break;
            }
        }

        if (found) 
        {
            if (LicenseType == Vc.Eligibility[vpos]) 
            {
                cout << "\nCar Eligible!!\nRental Details:\n";
                cout << "User ID: " << UserID << "\n";
                cout << "User Name: " << Name << "\n";
                cout << "User Age: " << Age << "\n";
                cout << "User License Type: " << LicenseType << endl;
                cout << "Rented Car Model: " << Vc.Model[vpos] << endl;
                cout << "Rented Car Price per day: " << Vc.RPD[vpos] << endl;
                cout << "Rented Car Eligibility: " << Vc.Eligibility[vpos] << endl;
            } 
            else 
            {
                cout << "Not Eligible for this car" << endl;
            }
        } 
        else 
        {
            cout << "Car Not found!!" << endl;
        }
    }

    void display() 
    {
        cout << "\nUser Details:\n";
        cout << "User ID: " << UserID << endl;
        cout << "User Name: " << Name << endl;
        cout << "User Age: " << Age << endl;
        cout << "User License Type: " << LicenseType << endl;
        cout << "Contact Number: " << Contact << endl;
    }
};

int User::Usercount = 0;

int main() 
{
    Vehicle V;
    User up;
    cout << "Registering User...." << endl;
    up.registerUser();

    int c;
    cout << "Do you want to update any User (1 for Yes, 0 for No): ";
    cin >> c;
    if (c == 1) 
    {
        up.update();
    }

    up.display();

    up.rent(V);
}
