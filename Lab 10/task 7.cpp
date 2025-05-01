#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outfile;
    char nl;
    outfile.open("sensor_log.txt",ios::app);
    if(!outfile)
    {
        cerr << "Error file sensor_log.txt no found" << endl;
        return 1;
    }
    outfile << "Sensor 3: 78.5\n";
    streampos pos = outfile.tellp();
    cout << "Current position: " << pos << endl;
    outfile << "Sensor 4: 120 F\n";
    pos = outfile.tellp();
    cout << "Current position: " << pos << endl;
    outfile << "Sensor 5: 5.7 ohm\n";
    pos = outfile.tellp();
    cout << "Current position: " << pos << endl;
 
    outfile.close();
}
