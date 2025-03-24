#include "iostream"
using namespace std;

class Media 
{
protected:
    string title;
    string publicationDate;
    static int uniqueID;
    string publisher;
    bool isCheckedOut;

public:
    Media(string t, string pd, string pb) : title(t), publicationDate(pd), publisher(pb), isCheckedOut(false) 
    {
        uniqueID++;    
    }

    int getID() const {
        return uniqueID;
    }

    virtual void displayInfo() 
    {
        cout << "Title: " << title << endl;
        cout << "ID: " << getID() << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Publisher: " << publisher << endl;
    }

    virtual void checkOut(string ti) 
    {
        if (ti == title) 
        {
            if (!isCheckedOut) 
            {
                isCheckedOut = true;
                cout << title << " Found! Process to lending." << endl;
            } 
            else 
            {
                cout << title << " is already checked out!" << endl;
            }
        } else {
            cout << "Not Found!" << endl;
        }
    }

    virtual void returnItem() 
    {
        if (isCheckedOut) 
        {
            isCheckedOut = false;
            cout << title << " has been successfully returned!" << endl;
        } 
        else
        {
            cout << title << " was not checked out." << endl;
        }
    }
};

int Media::uniqueID = 100;

class Book : public Media 
{
private:
    string author;
    string ISBN;
    int numOfPages;

public:
    Book(string t, string pd, string pb, string aut, string i, int num) 
        : Media(t, pd, pb), author(aut), ISBN(i), numOfPages(num) {}

    void displayInfo()  
    {
        cout << "----------Book Details-----------" << endl;
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Number of Pages: " << numOfPages << endl;
    }

    void checkOut(string ti, string aut) 
    {
        if (ti == title && aut == author) 
        {
            if (!isCheckedOut) 
            {
                isCheckedOut = true;
                cout << title << " Found! Process to lending." << endl;
            } 
            else 
            {
                cout << title << " is already checked out!" << endl;
            }
        } 
        else 
        {
            cout << "Book Not Found!" << endl;
        }
    }
};

class DVD : public Media 
{
private:
    string director;
    int duration;
    string rating;

public:
    DVD(string t, string pd, string pb, string dir, int dur, string rt) 
        : Media(t, pd, pb), director(dir), duration(dur), rating(rt) {}

    void displayInfo() 
    {
        cout << "----------DVD Details-----------" << endl;
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " hours" << endl;
        cout << "Rating: " << rating << endl;
    }

    void checkOut(string ti, string dir) 
    {
        if (ti == title && dir == director) 
        {
            if (!isCheckedOut) 
            {
                isCheckedOut = true;
                cout << title << " Found! Process to lending." << endl;
            } 
            else 
            {
                cout << title << " is already checked out!" << endl;
            }
        } 
        else 
        {
            cout << "DVD Not Found!" << endl;
        }
    }
};

class CD : public Media 
{
private:
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(string t, string pd, string pb, string art, int noft, string gr) 
        : Media(t, pd, pb), artist(art), numberOfTracks(noft), genre(gr) {}

    void displayInfo()
    {
        cout << "----------CD Details-----------" << endl;
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Number of Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }

    void checkOut(string ti, string art) 
    {
        if (ti == title && art == artist) 
        {
            if (!isCheckedOut) 
            {
                isCheckedOut = true;
                cout << title << " Found! Process to lending." << endl;
            } 
            else 
            {
                cout << title << " is already checked out!" << endl;
            }
        }
        else 
        {
            cout << "CD Not Found!" << endl;
        }
    }
};

int main() {
    Media* m1;

    Book b1("Harry Potter", "12/02/2001", "Rowling Publishers", "J.K. Rowling", "ISBN-0222445", 532);
    m1 = &b1;
    m1->displayInfo();
    b1.checkOut("Harry Potter", "J.K. Rowling");
    m1->displayInfo();
    m1->returnItem();
    m1->displayInfo();
    cout << endl;

    DVD d1("Tekken 8", "15/05/2024", "2K Games", "Unreal Director", 3, "4.5 Stars");
    m1 = &d1;
    m1->displayInfo();
    d1.checkOut("Tekken 8", "Unreal Director");
    m1->displayInfo();
    m1->returnItem();
    m1->displayInfo();
    cout << endl;

    CD c2("Smile", "04/06/2020", "Music & CO", "Juice World", 6, "POP");
    m1 = &c2;
    m1->displayInfo();
    c2.checkOut("Smile", "Juice World");
    m1->displayInfo();
    m1->returnItem();
    m1->displayInfo();
    cout << endl;
}
