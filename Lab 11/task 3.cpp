#include "iostream"
#include <sstream>
#include <fstream>
using namespace std;

class FileException{
    public:
    virtual const char * what()
    {
        return "Error!!\n";
    }
};

class FileNotFoundException : public FileException
{
    public:
    const char* what() const noexcept{
        return "FileNotFoundException - File Not Found\n";
    }
};

class PermissionDeninedException : public FileException{
    public:
    const char* what() const noexcept{
        return "PermissionDeninedException - Permission not granted\n";
    }
};

void readFile(const string& filename)
{
    ifstream file;
    string user,pass;
    file.open(filename);
    if(!file.is_open())
    {
        throw FileNotFoundException();
    }
    else
    {
        cout << "Enter user name to enter file: ";
        cin >> user;
        cout << "Enter Passsword: ";
        cin >> pass;
        if(user == "admin" && pass == "admin")
        {
            cout << "Reading " << filename << " - Permission Granted!!" << endl;
        }
        else
        {
            throw PermissionDeninedException();
        }
    }
}

int main()
{
    try{
        readFile("hello.txt");
    }
    catch(const FileNotFoundException& e)
    {
        cout << "Reading hello.txt " <<e.what() << endl;
    }

    try{
        readFile("vehicles.txt");
    }
    catch (const PermissionDeninedException& e)
    {
        cout << e.what() << endl;
    }
}
