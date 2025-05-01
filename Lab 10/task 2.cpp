#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file;
    string line;
    string type;
    string ID;
    string name;
    string year;
    string extra;
    string certification;
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
                
                istringstream rd(line);
                getline(rd,type,',');
                getline(rd,ID,',');
                getline(rd,name,',');
                getline(rd,year,',');
                getline(rd,extra,',');
                getline(rd,certification,',');
                cout << "Type: "<< type <<", ID: " << ID << ", Year: " << year << ", ExtraData: " << extra << ", Certification: " << certification << endl; 
            }
        }
    }
    file.close();
}
