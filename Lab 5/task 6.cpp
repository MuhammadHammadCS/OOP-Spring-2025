#include "iostream"
using namespace std;

class Movie{
    public:
        string title;
        string director;
        int duration;

    Movie(){}

    ~Movie()
    {
        cout << "Movie has been destroyed!!" << endl;
    }
};

class CinemaHall{
    private:
        Movie M;
    public:
        int num;
        string *mov;

    CinemaHall()
    {
        cout << "Enter the number of Movies: ";
        cin >> num;
        mov = new string[num];
        
        for (int i = 0; i < num; i++)
        {
            cout << "Enter Details for Movie " << i + 1 << endl;
            cout << "Enter Title: ";
            cin.ignore();
            getline(cin , M.title);
            cout << "Enter Director name: ";
            cin.ignore();
            getline(cin , M.director);
            cout << "Enter Movie Duration: ";
            cin >> M.duration;
            mov[i] = M.title;
            cout << endl;
        }
    }
    void display()
    {
        cout << "Displaying the movies currently screened: " << endl;
        for (int i = 0; i < num; i++)
        {
            cout << i + 1 << ". " << mov[i] << endl;  
        }
    }
    ~CinemaHall()
    {
        delete []mov;
        cout << "Destroying CinemaHall " << endl;
    }

};

int main()
{
    CinemaHall ch;
    ch.display();
}
