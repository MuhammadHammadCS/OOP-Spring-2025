#include "iostream"
using namespace std;

class Librarian;
class Book{
    private:
    string title;
    float price;

    public:
    Book(string t, float p) : title(t) , price(p){}

    friend class Librarian;
};

class Librarian{
    public:
    void display(const Book& b)
    {
        cout << "-------------------------" << endl;
        cout << "Title: " << b.title << endl;
        cout << "Price: " << b.price << endl;
        cout << "-------------------------" << endl;
    }

    void discount(Book &b , int amount)
    {
        b.price -= amount;
        cout << "Discounted Price: " << b.price << endl;
    }
};

int main()
{
    int amount;
    Book b("Harry Potter",120);
    Librarian lib;
    lib.display(b);
    cout << "Enter the discount: ";
    cin >> amount;
    lib.discount(b,amount);
    lib.display(b);
}
