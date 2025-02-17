#include "iostream"
using namespace std;

class Book 
{
public:
    string title;
    float price;
    float base_price;
    int stock;
    
    Book(string t, float p, int s) 
    {
        this->title = t;
        this->price = p;
        this->base_price = p;
        this->stock = s;
    }
    
    Book(const Book &b1) 
    {
        this->title = b1.title;
        this->base_price = b1.base_price;
        this->price = b1.price;
        this->stock = b1.stock;
    }
    
    void update(string t, float p) 
    {
        this->title = t;
        this->price = p;
        this->base_price = p;
    }
    
    void applydiscount(int p) 
    {
        float total = 0;
        int discount = 0;
        if (p > 5 && p <= 10) 
        {
            price = base_price * 0.95;
            discount = 5;
        } 
        else if (p > 10 && p <= this->stock) 
        {
            price = base_price * 0.90;
            discount = 10;
        } 
        else 
        {
            price = base_price;
        }
        total = price * p;
        cout << "Discount applied: " << discount << "%" << endl;
        cout << "New Price: " << this->price << endl;
        cout << "Total Price: " << total << endl;
    }
    
    void purchase(int p) 
    {
        if (p > this->stock) 
        {
            cout << "Not enough books available! Maximum Quantity: " << this->stock << endl;
        } 
        else 
        {
            this->stock -= p;
            cout << "Purchase successful! Remaining stock: " << this->stock << endl;
        }
        if (this->stock < 5) 
        {
            cout << "Low-Stock Warning" << endl;
        }
    }
    
    void track() 
    {
        cout << "Current Stock Level: " << this->stock << endl;
    }
    
    void display() 
    {
        cout << "Title: " << title << endl;
        cout << "Base Price: " << base_price << endl;
        cout << "Current Price: " << price << endl;
        cout << "Stock: " << this->stock << endl;
    }
    
    ~Book() 
    {
        cout << "Object has been destroyed!!!\n";
    }
};
  
int main() 
{
    Book bk("Harry Potter", 50.0, 50);
    Book bk1(bk);
    bk.display();
    
    int p;
    cout << "Enter the amount of books you want to purchase: ";
    cin >> p;
    bk.applydiscount(p);
    bk.purchase(p);
    bk.display();
    bk.track();
    
    int q;
    cout << "Enter the amount of books you want to purchase in another copy: ";
    cin >> q;
    bk1.update("C++", 40.0);
    bk1.applydiscount(q);
    bk1.purchase(q);
    bk1.display();
    bk1.track();
    
    cout << "\nAfter purchasing in both objects: " << endl;
    bk.display();
    bk1.display();
    
}
