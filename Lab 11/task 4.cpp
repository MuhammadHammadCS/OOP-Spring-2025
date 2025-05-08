#include "iostream"
#include <exception>
#include <math.h>
using namespace std;

class NegativeNumberException{
    public:
    const char* what() const noexcept
    {
        return "NegativeNumberException - Input number should be non negative!";
    }
};
class InvalidTypeException{
    public:
    const char* what() const noexcept
    {
        return "InvalidTypeException - Non numeric type detected";
    }
};
template<typename T>
T sqrtz(T num)
{
    if(num < 0)
    {
        throw NegativeNumberException();
    }
    else
    {
        return sqrt(num);
    }
}
double sqrtz(const char* num) 
{
    throw InvalidTypeException();
}

double sqrtz(string num) 
{
    throw InvalidTypeException();
}
int main()
{
    int integer = 16;
    int negative = -4;
    string word = "hello";
    try{
        cout << sqrtz(word) << endl;
    }
    catch(const NegativeNumberException& ng){
        cout << "sqrt ( " << negative << " ) " << ng.what() << endl;
    }
    catch (const InvalidTypeException & iv)
    {
        cout << "sqrt ( " << word<< " ) " << iv.what() << endl; 
    }
    try{
        cout << "Answer: " << sqrtz(integer) << endl;
    }
    catch(const NegativeNumberException& ng){
        cout << "sqrt ( " << negative << " ) " << ng.what() << endl;
    }
    catch (const InvalidTypeException & iv)
    {
        cout << "sqrt ( " << word<< " ) " << iv.what() << endl; 
    }
    try{
        cout << sqrtz(negative) << endl;
    }
    catch(const NegativeNumberException& ng){
        cout << "sqrt ( " << negative << " ) " << ng.what() << endl;
    }
    catch (const InvalidTypeException & iv)
    {
        cout << "sqrt ( " << word<< " ) " << iv.what() << endl; 
    }
}
