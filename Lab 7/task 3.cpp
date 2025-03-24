#include "iostream"
using namespace std;

class Currency{
    protected:
    float amount;
    string currencyCode;
    char currencySymbol;
    float exchangeRate;

    public:
    Currency(float amount,string currencyCode,char currencySymbol,float exchangeRate) : amount(amount) , currencyCode(currencyCode) , currencySymbol(currencySymbol) , exchangeRate(exchangeRate){}

    virtual void convertToBase()
    {
        cout << "Coverting to Base Currnecy!!" << endl;
    }

    virtual void convertTO(string targetCurrency)
    {
        cout << "Converting to the currency targeted" << endl;
    }

    virtual void displayCurrency()
    {
        cout << "Currency Symbol: " << currencySymbol << endl;
        cout << "Currency Code: " << currencyCode << endl;
        cout <<  "Amount: " << amount << endl;
        cout << "Exchange Rate: " << exchangeRate << endl;
    }
};

class Dollar : public Currency
{
    public:
    Dollar(float amount,string currencyCode,char currencySymbol,float exchangeRate) : Currency(amount,currencyCode,currencySymbol,exchangeRate){}

    void convertToBase()
    {
        cout << "Base Currency: Kuwaiti Dinar" << endl;
        cout << currencyCode << " to KWD: " << amount/3.24 << endl;
    }

    void convertTO(string targetCurrency)
    {
        if(targetCurrency == "Rupee")
        {
            amount = amount * 280;
            cout << "Amount converted to Rupee form " << currencyCode << endl;
        }
        else if(targetCurrency == "Euro")
        {
            amount = amount * 0.92;
            cout << "Amount converted to Euro form " << currencyCode << endl;
        }
        else if(targetCurrency == "Dollar")
        {
            cout << "NO conversion Same Currnecyy Code" << endl;
        }
        cout << "Converted Amount: " << amount << endl;
    }
    void displayCurrency()
    {
        cout << "Currency Symbol: " << currencySymbol << endl;
        cout << "Currency Code: " << currencyCode << endl;
        cout << "Amount in USD: " << amount << endl;
        cout << "Exchange Rate: " << exchangeRate << endl;
    }
};

class Euro : public Currency
{
    public:
    
    Euro(float amount,string currencyCode,char currencySymbol,float exchangeRate) : Currency(amount,currencyCode,currencySymbol,exchangeRate){}

    void convertToBase()
    {
        cout << "Base Currency: Kuwaiti Dinar" << endl;
        cout << currencyCode << " to KWD: " << amount/2.99 << endl;
    }

    void convertTO(string targetCurrency)
    {
        if(targetCurrency == "Rupee")
        {
            amount = amount * 303.24;
            cout << "Amount converted to Rupee form " << currencyCode << endl;
        }
        else if(targetCurrency == "Dollar")
        {
            amount = amount * 1.08;
            cout << "Amount converted to Dollar form " << currencyCode << endl;
        }
        else if(targetCurrency == "Euro")
        {
            cout << "NO conversion Same Currnecy Code" << endl;
        }
        cout << "Converted Amount: " << amount << endl;
    }
    void displayCurrency()
    {
        cout << "Currency Symbol: " << currencySymbol << endl;
        cout << "Currency Code: " << currencyCode << endl;
        cout << "Amount: " << amount << endl;
        cout << "Exchange Rate: " << exchangeRate << endl;
    }

};

class Rupee : public Currency
{
    public:
    Rupee(float amount,string currencyCode,char currencySymbol,float exchangeRate) : Currency(amount,currencyCode,currencySymbol,exchangeRate){}

    void convertToBase()
    {
        cout << "Base Currency: Kuwaiti Dinar" << endl;
        cout << currencyCode << " to KWD: " << amount*0.0011 << endl;
    }
    void convertTO(string targetCurrency)
    {
        if(targetCurrency == "Dollar")
        {
            amount = amount*0.0036;
            cout << "Amount converted to Dollar form " << currencyCode << endl;
        }
        else if(targetCurrency == "Euro")
        {
            amount = amount*0.003299;
            cout << "Amount converted to Euro form " << currencyCode << endl;
        }
        else if(targetCurrency == "Rupee")
        {
            cout << "NO conversion Same Currnecy Code" << endl;
        }
        cout << "Converted Amount: " << amount << endl;
    }
    void displayCurrency()
    {
        cout << "Currency Symbol: " << currencySymbol << endl;
        cout << "Currency Code: " << currencyCode << endl;
        cout << "Amount: " << amount << endl;
        cout << "Exchange Rate: " << exchangeRate << endl;
    }
};

int main()
{
    Currency *c1;
    Dollar d1(100,"USD",'$',20.6);
    c1 = &d1;
    c1->displayCurrency();
    c1->convertToBase();
    c1->convertTO("Euro");
    cout << endl;
    Euro e1(200,"EUR",'E',30.45);
    c1 = &e1;
    c1->displayCurrency();
    c1->convertToBase();
    c1->convertTO("Rupee");
    cout << endl;
    Rupee r1(40000,"PKR",'R',280);
    c1 = &r1;
    c1->displayCurrency();
    c1->convertToBase();
    c1->convertTO("Dollar");
}
