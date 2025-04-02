#include "iostream"
using namespace std;


class Fraction{
    private:
    int numertor;
    int denominator;
    public:
    Fraction(int n = 0 , int d = 1) : numertor(n) , denominator(d) {}
    Fraction operator+(Fraction &f1)
    {
        if(denominator == 0 || f1.denominator == 0)
        {
            cout << "MATH Error!!!" << endl;
            return 0;
        }
        else if(denominator == f1.denominator)
        {
            return Fraction(numertor + f1.numertor,denominator);
        }
        else
        {
            numertor = numertor * f1.denominator;
            f1.numertor = f1.numertor * denominator;
            if(denominator > f1.denominator)
            {
                return Fraction(numertor + f1.numertor,denominator*f1.denominator);
            }
            else
            {
                return Fraction(numertor + f1.numertor,f1.denominator*denominator);
            }
        }
    }
    Fraction operator-(Fraction &f1)
    {
        if(denominator == 0 || f1.denominator == 0)
        {
            cout << "MATH Error!!!" << endl;
            return 0;
        }
        else if(denominator == f1.denominator)
        {
            return Fraction(numertor - f1.numertor,denominator);
        }
        else
        {
            numertor = numertor * f1.denominator;
            f1.numertor = f1.numertor * denominator;
            if(denominator > f1.denominator)
            {
                return Fraction(numertor - f1.numertor,denominator*f1.denominator);
            }
            else
            {
                return Fraction(numertor - f1.numertor,f1.denominator*denominator);
            }
        }
    }
    Fraction operator*(Fraction &f)
    {
        if(denominator == 0 || f.denominator == 0)
        {
            cout << "MATH Error!!!" << endl;
            return 0;
        }
        else
        {
            return Fraction(numertor*f.numertor , denominator*f.denominator);
        }
        
    }
    Fraction operator/(Fraction &f)
    {
        if(denominator == 0 || f.denominator == 0)
        {
            cout << "MATH Error!!!" << endl;
            return 0;
        }
        else
        {
            return Fraction(numertor/f.numertor , denominator/f.denominator);
        }
        
    }
    friend ostream& operator<<(ostream& os , Fraction& f);

};

ostream& operator<<(ostream& os , Fraction&f)
{
    os << f.numertor << "/" << f.denominator;
    return os;
}


int main()
{
    Fraction f1(10,6) , d1(5,3) ,f2 , f3 , f4 , f5;
    cout << "f1: " << f1 << " , d1: " << d1 << endl;
    cout << endl;
    f4 = f1 * d1;
    f5 = f1 / d1;
    f2 = f1 + d1;
    f3 = d1 - f1;
    cout << "Fraction Addition: " << endl;
    cout << "f1 + d1: " << f2 << endl;
    cout << "Fraction Subtraction: " << endl;
    cout << "d1 - f1: " << f3 << endl;
    cout << "Fraction Multiplication: " << endl;
    cout << "f1 * d1: " << f4 << endl;
    cout << "Fraction Divison: " << endl;
    cout << "f1 / d1: " << f5 << endl;

}
