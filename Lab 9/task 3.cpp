#include "iostream"
#include "Book.hpp"
using namespace std;

const int MAX_BOOK = 10;
class Library{
    private:
    Book b1[MAX_BOOK];
    int bookcount = 0;
    
    public:
    

    void addBook(Book b)
    {
        if(bookcount < MAX_BOOK)
        {
            b1[bookcount] = b;
            bookcount++;
            cout << "Book Added successfully" << endl;
        }
    }
    void removeBook()
    {
        int index;
        cout << "Enter the index to remove the book(1-10): ";
        cin >> index;
        if(index - 1 < 1 || index - 1 > bookcount)
        {
            cout << "Invalid Index" << endl;
        }
        else
        {
            for (int i = index - 1; i < bookcount - 1; i++)
            {
                b1[i] = b1[i+1];
            }
            bookcount--;
            cout << "Book Removed successfully" << endl;
        }
    }
    void searchBook(string ISBN)
    {
        bool found = false;
        for (int i = 0; i < bookcount; i++)
        {
            if(ISBN == b1[i].getISBN())
            {
                found = true;
                cout << "Book Found!!" << endl;
                cout << "Book title: " << b1[i].getTitle() << endl;
                cout << "Book Author: " << b1[i].getAuthor() << endl;
                cout << "Book ISBN: " << b1[i].getISBN() << endl;
                cout << endl;
                break;
            }
        }
        if(!found)
        {
            cout << "Book not found!" << endl;
        }
    }

    void displayall()
    {
        for (int i = 0; i < bookcount; i++)
        {
            cout << "Book " << i + 1 << endl;
            cout << "Book title: " << b1[i].getTitle() << endl;
            cout << "Book Author: " << b1[i].getAuthor() << endl;
            cout << "Book ISBN: " << b1[i].getISBN() << endl;
        }
        
    }
};

int main()
{
    Book b1("Sapiens: A Brief History of Humankind" ,"Yuval Noah Harari" , "9780062316097");
    Book b2("To Kill a Mockingbird","Harper Lee","9780061120084");
    Book b3("1984","George Orwell","9780");
    Library lib;

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);

    lib.displayall();
    cout << endl;
    string isbn;
    cout << "Enter ISBN to search: ";
    cin >> isbn;
    lib.searchBook(isbn);

    lib.removeBook();
    lib.displayall();
    cout << endl;
}
