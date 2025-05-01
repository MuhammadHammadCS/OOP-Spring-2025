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
    string ac;
    string ev;
    size_t pos;
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
                if(type == "AutonomousCar")
                {
                    pos = extra.find(':');
                    if(pos != extra.npos)
                    {
                        pos = pos + 1;
                        ac = extra.substr(pos,',');
                        cout << "Vehicle ID: " << ID << endl;
                        cout << "Software Version in floating point number: " << stof(ac) << "\n" <<endl;
                    }
                    else
                    {
                        cout << "No colon found!!" << endl;
                    }
                }
                
                if(type == "ElectricVehicle")
                {
                    pos = extra.find(':');
                    if(pos != extra.npos)
                    {
                        pos = pos + 1;
                        ev = extra.substr(pos,',');
                        cout << "Vehicle ID: " << ID << endl;
                        cout << "Battery Capcity in integer: " << stoi(ev) << endl;
                    }
                    else
                    {
                        cout << "No colon found!!" << endl;
                    }
                }
            }
        }
    }
    file.close();
}
