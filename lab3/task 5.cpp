#include "iostream"
using namespace std;


class GroceryStore
{
    public:
    int n;
    string *items = new string[n];
    int *prices = new int[n];
    void additems(string *items,int *prices, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter Item " << i + 1 << ": ";
            cin.ignore();
            getline(cin , items[i]);
            cout << "Enter price for item " << i + 1 << ": ";
            cin >> prices[i];
        } 
    }
    void updateprice(string *items,int *prices, int n)
    {
        bool found =  false;
        string find;
        int k;
        cout << "Enter the item name to update price for: ";
        cin.ignore();
        getline(cin , find);
        for (int i = 0; i < n; i++)
        {
            if(items[i] == find)
            {
                found = true;
                k = i;
                break;
            }
        }
        if(found)
        {
            cout << "Enter the new price for the item " << items[k] << " : ";
            cin >> prices[k];
        }
        else
        {
            cout << "NO item found!!" << endl;
        }
    }
    void viewinv(string *items,int *prices, int n)
    {
        cout << "Viewing Inventory......" << endl;
        cout << "Items: \t Prices: \n";
        for (int i = 0; i < n; i++)
        {
            cout << items[i] << " \t " << prices[i] << endl;
        }
        
    }
    void generate(string *items,int *prices, int n)
    {
        if(n == 0)
        {
            cout << "Inventory empty!" << endl;
        }
        int order;
        cout << "Enter the number of items you have picked: ";
        cin >> order;
        bool find;
        int total = 0;
        string *orders = new string[order];
        int *ordcount = new int[order];
        if(order > n)
        {
            cout << "Not Enough item in stock "<< endl;
        }
        else
        {
            for (int i = 0; i < order; i++)
            {
                cout << "Enter item " << i + 1 << " : ";
                cin.ignore();
                getline(cin , orders[i]);

                cout << "Enter quantity for " << orders[i] << ": ";
                cin >> ordcount[i];
                cout << "\nReceipt:\n";
                cout << "---------------------------------\n";
                cout << "Item\t\tQuantity\tPrice\tTotal\n";
                cout << "---------------------------------\n";

        for (int i = 0; i < order; i++) 
        {
            bool found = false;
            for (int j = 0; j < n; j++) 
            {
                if (orders[i] == items[j]) 
                {
                    if (ordcount[i] > 999) 
                    {
                        cout << orders[i] << "\t\t" << ordcount[i] 
                             << "\t\tNot enough stock\n";
                    } 
                    else 
                    {
                        int itemTotal = prices[j] * ordcount[i];
                        cout << orders[i] << "\t\t" << ordcount[i] << "\t\t" 
                             << prices[j] << "\t" << itemTotal << endl;
                        total += itemTotal; 
                    }
                    found = true;
                    break;
                }
            }
            if (!found) 
            {
                cout << orders[i] << "\t\t" << ordcount[i] << "\t\tNot Available\n";
            }
        }

        cout << "---------------------------------\n";
        cout << "Grand Total: \t\t\t" << total << endl;
        cout << "---------------------------------\n";

        delete[] orders;
        delete[] ordcount;
    
        }
    }

    }
};

int main()
{
    GroceryStore gs;
    int choice;
    gs.n;
    gs.items;
    gs.prices;
    cout << "Inventory Management System" << endl;
    while(choice != 5)
    {
        cout << "1.Add items\n2.Update prices\n3.View inventory\n4.Generate receipt\n5.Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the number of items to add: ";
            cin >> gs.n;
            gs.additems(gs.items , gs.prices , gs.n);
            break;
        case 2:
            gs.updateprice(gs.items , gs.prices , gs.n);
            break;
        case 3:
            gs.viewinv(gs.items , gs.prices , gs.n);
            break;
        case 4:
            gs.generate(gs.items , gs.prices , gs.n);
            break;
        case 5:
            cout << "Exiting........" << endl;
            break;
        default:
            cout << "Invalid choice!!" << endl;
            break;
        }

    }
    delete []gs.items;
    delete []gs.prices;
}
