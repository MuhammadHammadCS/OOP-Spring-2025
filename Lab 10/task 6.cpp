#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class InventoryItem{
    public:
    int itemID;
    char itemName[20];
};

int main()
{
    InventoryItem items = {1001, "Shoes"};
    ofstream file("inventory.dat",ios::binary);
    if(file.is_open())
    {
        file.write((char*)&items , sizeof(items));
    }
    else
    {
        cout << "inventory.dat can't open so can't write" << endl;
    }
    file.close();

    InventoryItem item1;
    ifstream infile("inventory.dat",ios::binary);
    if(infile.is_open())
    {
        infile.read((char*)&item1 , sizeof(item1));
    }
    else
    {
        cout << "inventory.dat can't open so can't read" << endl;
    }
    infile.close();

    cout << "Read form inventory.dat" << endl;
    cout << "Item ID: " << item1.itemID << endl;
    cout << "item Name: " << item1.itemName << endl;
}
