#include "iostream"
using namespace std;

class Product
{
    public:
    static int ID;
    string *category;
    string *name;
    float *price;

};
class Inventory
{
    private:
        Product p;
    public:
        int count;
        int *ID;
    Inventory()
    {
        cout << "Enter the number of products to store in Inventory: ";
        cin >> count;
        p.category = new string[count];
        p.name = new string[count];
        p.price = new float[count];
        ID = new int[count];
        cout << endl;
        for (int i = 0; i < count; i++)
        {
            cout << "Enter Category for product " << i + 1 << ": ";
            cin >> p.category[i];
            cout << "Enter Name for product " << i + 1 << ": ";
            cin >> p.name[i];
            cout << "Enter Price for product " << i + 1 << ": ";
            cin >> p.price[i];
            ID[i] = p.ID++;
            cout << endl;
        }
    }
    void Search()
    {
        string item;
        bool find;
        int pos;
        cout << "Enter product Name to search for: ";
        cin >> item;
        for (int i = 0; i < count; i++)
        {
            if(item == p.name[i])
            {
                find = true;
                pos = i;
                break;
            }
        }
        if(find)
        {
            cout << "Product ID: " << ID[pos] << endl;
            cout << "Product Price: " << p.price[pos] << endl;
            cout << "Product Category: " << p.category[pos] << endl; 
        }
        else
        {
            cout << "Product Not found!" << endl;
        }
    }
    void sort()
    {
        for (int i = 0; i < count - 1; i++) 
        {
            int minIndex = i;
            for (int j = i + 1; j < count; j++) 
            {
                if (p.price[j] < p.price[minIndex]) 
                {
                    minIndex = j;
                }
            }
            swap(p.price[i], p.price[minIndex]);
            swap(p.name[i], p.name[minIndex]);
        }
        cout << "Products sorted by price in ascending order:" << endl;
        for (int i = 0; i < count; i++) 
        {
            cout << i + 1 << ". Product: " << p.name[i] << "  Price: " << p.price[i] << endl;
        }
    }
};

int Product :: ID = 101;
int main()
{
    Inventory inv;
    cout << endl;
    inv.Search();
    cout << endl;
    inv.sort();
}
