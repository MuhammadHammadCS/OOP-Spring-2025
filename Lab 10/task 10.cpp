#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile;
    string line;
    string ln;
    infile.open("data_records.txt",ios::binary);
    if(!infile.is_open())
    {
        cout << "Error in opening data_record.txt" << endl;
    }
    for (int i = 0; i < 2; i++)
    {
        getline(infile,line,'\n');
    }
    streampos pos = infile.tellg();
    infile.seekg(pos,ios::beg);
    getline(infile,ln);
    cout << "Record on the third line: " << ln << endl;
    infile.close();
}
