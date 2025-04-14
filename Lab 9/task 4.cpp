#include "iostream"
using namespace std;


class PaymentMethod{
    protected:
    virtual void processPayment(double amount) = 0;
};

class CreditCard : public PaymentMethod{
    private:
    string cardNumber;
    public:
    CreditCard(string cn)
    {
        cardNumber = cn;
    }

    void processPayment(double amount)
    {
        if(amount > 0)
        {
            cout << "Amount " << amount << " processed successfully" << endl;
        }
        else
        {
            cout << "Invalid Amount" << endl;
        }
    }

};

class DigitalWallet : PaymentMethod{
    private:
    double balance;

    public:
    DigitalWallet(double b)
    {
        balance = b;
    }

    void processPayment(double amount)
    {
        if(amount > 0 && amount < balance)
        {
            cout << "Amount " << amount << " deducted successfully" << endl;
            balance -= amount;
            cout << "Remaining Balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid Amount" << endl;
        }
    }
};

int main()
{
    CreditCard cd("4555-66667-7765");
    DigitalWallet dw(5000);
    cout<< "----------Credit Card----------" << endl;
    cd.processPayment(500);

    cout<< "----------Digital Wallet----------" << endl;
    dw.processPayment(2000);
}
