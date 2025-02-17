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
    Book(Book &b1)
    {
        title = b1.title;
        price = b1.price;
        *stock = *b1.stock;
    }
    void update(string t, float p)
    {
      title = t;
      price = p;
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
            cout << "Not enough books available!\n Maximum Quantity:  "<< *stock << endl;
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
    ~Book()
    {
        delete []stock;
        cout << "Object has been destoryed!!!\n";
    }
  };
  
int main()
{
    Book bk("Harry Potter",50.0,50);
    Book bk1(bk);
    bk.display();
    int p;
    cout << "Enter the amount of book you want to purchase: ";
    cin >> p;
    bk.applydiscount(p);
    bk.purchase(p);
    bk.display();
    bk.track();
    int q;
    cout << "Enter the amount of book you want to purchase in another copy: ";
    cin >> q;
    bk1.update("C++" , 40.0);
    bk1.applydiscount(q);
    bk1.purchase(q);
    bk1.display();
    bk1.track();
    cout << endl;
    cout << "After purchasing in both objects: " << endl;
    bk.display();
    bk1.display();
}
