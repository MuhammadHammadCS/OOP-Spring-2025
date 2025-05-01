#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    fstream file("config.txt",ios::in | ios::out);
    string line;
    if(!file.is_open())
    {
        cout << "Not able to open the file config.txt" << endl;
    }
    file.seekg(ios::beg);
    file.seekg(5);
    file.write("XXXXX",5);
    file.close();
    file.open("config.txt");
    cout << "After update: ";
    while(getline(file,line))
    {
        cout << line << endl;
    }
    file.close();
}
