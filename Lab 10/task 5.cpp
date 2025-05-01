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
    string ht1;
    string ht2 , ht21;
    size_t pos;
    bool found;
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
                if(type == "HybridTruck")
                {
                    found = true;
                    pos = extra.find(':');
                    if(pos != extra.npos)
                    {
                        pos = pos + 1;
                        ht1 = extra.substr(pos,'|');
                        cout << "Vehicle ID: " << ID << endl;
                        cout << "Cargo in integer: " << stoi(ht1) << "\n" <<endl;
                    }
                    else
                    {
                        cout << "No colon found!!" << endl;
                    }
                    pos = extra.find('|');
                    if(pos = extra.npos)
                    {
                        pos = pos + 1;
                        ht2 = extra.substr(pos,',');
                        pos = ht2.find(':');
                        pos = pos + 1;
                        ht21 = ht2.substr(pos,',');
                        cout << "Battery in integer: " << stoi(ht21) << "\n" <<endl;
                    }
                    else
                    {
                        cout << "No pipe found!!" << endl;
                    }
                }
                if(!found)
                {
                    cout << "Invalid Vehicle type" << endl;
                }
                
            }
        }
    }
    file.close();
}
