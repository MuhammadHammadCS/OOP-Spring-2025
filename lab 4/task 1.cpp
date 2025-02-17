#include "iostream"
using namespace std;

class Book{
    public:
    string title;
    float price;
    int *stock = new int[30];
    
    Book()
    {
        title = "Unknown";
        price = 0.0;
        *stock = 30;
    }
    void update(string t, float p)
    {
      title = t;
      price = p;
    }
    void purchase()
    {
        int p;
        cout << "Enter the amount of book you wnat to purchase: ";
        cin >> p;
        if(p > 30)
        {
            cout << "Not enough books available " << endl;
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
    Book bk;
    bk.display();
    bk.update("Harry Potter",50.0);
    bk.display();
    bk.purchase();
    bk.track();
  }
