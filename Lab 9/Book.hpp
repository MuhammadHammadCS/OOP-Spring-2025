#pragma once
#include "iostream"
using namespace std;
class Book{
    private:
    string title;
    string author;
    string ISBN;
    public:
    Book(string t="Unknown", string a="Unknown", string I="420") : title(t) , author(a) , ISBN(I){}

    string getTitle()
    {
        return title;
    }
    string getAuthor()
    {
        return author;
    }
    string getISBN()
    {
        return ISBN;
    }
};

