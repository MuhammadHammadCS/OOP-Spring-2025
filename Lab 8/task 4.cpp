#include "iostream"
using namespace std;

class Currency{
    private:
    int value;
    public:
    Currency(int val = 0) : value(val){}
    Currency operator-()
    {
        return Currency(-value);
    }
    Currency operator+(Currency &c1)
    {
        return Currency(value + c1.value);
    }
    Currency operator-(Currency &c1)
    {
        return Currency(value - c1.value);
    }
    Currency& operator+=(Currency &c1)
    {
        value += c1.value;
        return *this;
    }
    Currency& operator-=(Currency &c1)
    {
        value -= c1.value;
        return *this;
    }
    friend ostream& operator<<(ostream &os, Currency &c1);
};
ostream& operator<<(ostream &os, Currency &c1)
{
    os << c1.value;
    return os;
}

int main()
{
    Currency c1(80) , c2 , c3(20);
    cout << "C1 : " << c1 << " , C3: " << c3 << endl;
    cout << endl;
    c2 = c1 + c3;
    cout << "c2 = c1 + c3: " << c2 << endl;
    c2 = c1 - c3;
    cout << "c2 = c1 - c3: " << c2 << endl;
    Currency c4(10) , discount(20);
    cout << endl;
    cout << "C4 : " << c4 << " , discount: " << discount << endl;
    c2 += c4;
    cout << "c2 += c4: " << c2 << endl;
    c2 -= discount;
    cout << "c2 -= discount: " << c2 << endl;
    c1 = -c1;
    cout << endl;
    cout << "Negative c1: " << c1 << endl;
}
