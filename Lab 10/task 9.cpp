#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file;
    file.open("large_log.txt",ios::binary);
    char line[10];
    if(!file.is_open())
    {
        cout << "Error in open large_log.txt!" << endl;
        return 1;
    }

    file.read(line,10);
    streampos pos = file.tellg();
    cout << "Current position after reading first 10 char: " << pos << endl;
    while(file.read(line,10))
    {
        pos = file.tellg();
        cout << "Current position after reading 10 char: " << pos << endl;
    }
}
