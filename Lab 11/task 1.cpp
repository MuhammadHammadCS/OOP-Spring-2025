#include "iostream"
#include <sstream>
using namespace std;


class Exception{
    public:
    virtual const char* what() 
    {
        return "Error!!!\n";
    }
};
class InvalidValueException : public Exception{
    public:
    const char* what() const noexcept
    {
        return "Error: Age cannot be negative or exceed 120";
    }
};
void validateAge(int age)
{
    if(age < 0 || age > 120)
    {
        throw InvalidValueException();
    }
}
int main()
{
    int age; 
    cout << "Enter the Age: ";
    cin >> age;

    try
    {
        validateAge(age);
        cout << "Valid Age Entered: " << age << endl;
    }
    catch(const InvalidValueException& e)
    {
        cout << "Error: InvalidValueException" << endl;
        cout << e.what() << '\n';
    }
}
