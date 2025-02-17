#include "iostream"
using namespace std;


class Book{
    public:
    string title;
    float price;
    int s;
    int *stock = new int[s];
    
    Book(string t, float p, int s)
    {
        title = t;
        price = p;
        *stock = s;
    }
    void applydiscount(int p)
    {
        if(p > 5 && p <= 10)
        {
            price *= 0.95;
            cout << "5 percent discount applied for more than 5 copies" << endl;
            cout << "New Price: " << price << endl;
        }
        else if(p > 10 && p < *stock)
        {
            price *= 0.90;
            cout << "10 percent discount applied for more than 10 copies" << endl;
            cout << "New Price: " << price << endl;
        }
        else 
        {
            cout << "No discount will be applied " << endl;
        }
    }
    void purchase(int p)
    {
        if(p > *stock)
        {
            cout << "Not enough books available!\n Maximum Quantity:  "<< stock << endl;
        }
        else
        {
            *stock -= p;
        }
        if(*stock < 5)
        {
            cout << "Low-Stock Warning" << endl;
        }
    }
    void track()
    {
        cout << "Current Stock Level: " << *stock << endl;
    }
    void display()
    {
        cout << "Title: " << title << endl << "Price: " << price << endl << "Stock: " << *stock << endl;
    }
  };
  
int main()
    {
    Book bk("Harry Potter",50.0,30);
    bk.display();
    int p;
    cout << "Enter the amount of book you want to purchase: ";
    cin >> p;
    bk.applydiscount(p);
    bk.purchase(p);
    bk.display();
    bk.track();
}
