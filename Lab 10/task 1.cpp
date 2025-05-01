#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file;
    string line;
    file.open("vehicles.txt");

    if(!file.is_open())
    {
        cout << "Error file vehicles.txt cannot be opened" << endl;
    }
    else
    {
        while(getline(file , line))
        {
            if(!line.empty() && line[0] != '/')
            {
                cout << line << endl;
            }
        }
    }
    file.close(); 
}
