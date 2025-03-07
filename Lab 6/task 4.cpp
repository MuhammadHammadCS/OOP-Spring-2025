#include "iostream"
using namespace std;

class Account{
    protected:
    int accountNumber;
    float balance;

    public:
    Account(int accountNumber , float balance) : accountNumber(accountNumber) , balance(balance){}

    void displayDetails()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account{
    public:
    float interestRate;

    SavingsAccount(int accountNumber , float balance, float interestRate) : Account(accountNumber , balance) , interestRate(interestRate){}

    void displayDetails()
    {
        cout << "Savings Account " << endl;
        Account :: displayDetails();
        cout << "Interest Rate: " << interestRate << endl;
    }
};

class checkingAccount : public Account{
    public:
    float overdraftlimit;

    checkingAccount(int accountNumber , float balance, float overdraftlimit) : Account(accountNumber , balance) , overdraftlimit(overdraftlimit){}

    void displayDetails()
    {
        cout << "Checking Account " << endl;
        Account :: displayDetails();
        cout << "Over Draft Limit: " << overdraftlimit << endl;
    }
};

int main(){
    SavingsAccount sv(121345, 500, 12.6);
    checkingAccount ca(69585686, 1000 , 30.9);

    sv.displayDetails();
    cout << endl;
    ca.displayDetails();
}
