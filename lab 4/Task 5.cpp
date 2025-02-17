#include "iostream"
using namespace std;


class Book 
{
    private:
    static int count;
    int BookID;

    public:
    string title;
    float price;
    float base_price;
    int stock;
    
    Book(): BookID(++count)
    {
        cout << "The Book ID: " << BookID << endl;
        cout << "Enter the Title of the book: ";
        cin >> this->title;
        cout << "Enter the base price of the book: ";
        cin >> this->base_price;
        cout << "Enter the Stock of the book: ";
        cin >> this->stock;
    }
    
    Book(const Book &b1): BookID(++count)
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
        cout << "Book ID: " << BookID << endl;
        cout << "Title: " << this->title << endl;
        cout << "Base Price: " << this->base_price << endl;
        cout << "Stock: " << this->stock << endl;
        
    }
    
    ~Book() 
    {
        cout << "Object has been destroyed!!!\n";
    }
};

int Book :: count = 1000;
int main() 
{
    Book bk;
    Book bk1;
    int p;
    cout << "Enter the amount of books you want to purchase: ";
    cin >> p;
    bk.applydiscount(p);
    bk.purchase(p);
    bk.track();
    bk1.applydiscount(p);
    bk1.purchase(p);;
    bk1.track();
    bk.display();
    bk1.display();
}
