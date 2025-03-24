#include "iostream"
using namespace std;

class Account
{
protected:
    int accountNumber;
    int balance;
    string accountHolderName;
    int Deposit, Withdraw;

public:
    Account(){}
    Account(int an, int b, string name) : accountNumber(an), balance(b), accountHolderName(name) {}

    void deposit(int amount)
    {
        balance += amount;
        Deposit += amount;
        cout << "$ " << amount << " deposited successfully " << endl;
    }

    virtual void withdraw(int amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            Withdraw += amount;
            cout << "$ " << amount << " withdraw successfully " << endl;
        }
        else
        {
            cout << "Insufficient Funds " << endl;
        }
    }

    virtual void calculateInterest()
    {
        int interest;
        if (balance > 5000)
        {
            interest = balance * 0.50;
            cout << "Interest calculated: " << interest << endl;
        }
    }
    virtual void printStatement()
    {
        cout << "Transition history " << endl;
        cout << "Total amount Depsoit: " << Deposit << endl;
        cout << "Total amount Withdraw: " << Withdraw << endl;
        cout << "Current Balance: " << balance << endl;
    }
    void getinfo()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Intial Balance: " << balance << endl;
    }
};

class SavingAcount : public Account
{
private:
    float InterestRate;
    int minimum_balance;
    int amount;

public:
    SavingAcount(int an, int b, string name, float ir, int min) : Account(an, b, name), InterestRate(ir), minimum_balance(min) {}

    void calculateInterest()
    {
        if (balance >= minimum_balance)
        {
            cout << "Interest applied: " << InterestRate << " %" << endl;
            amount = balance * (InterestRate/100);
            balance = balance - amount;
            cout << "New Balance: " << balance << endl;
        }
    }

    void printStatement()
    {
        cout << "Transition history " << endl;
        cout << "Current Balance: " << balance << endl;
        cout << "Minimum Balance Required: " << minimum_balance << endl;
    }
    void withdraw(int amount)
    {
        if (amount > minimum_balance)
        {
            balance -= amount;
            Withdraw += amount;
            cout << "$ " << amount << " withdraw as greater than minimum balance successfully " << endl;
        }
        else
        {
            cout << "Less than minimum balance " << endl;
        }
    }
};

class CheckingAccount : protected Account
{
};

class FixedDepositAccount : public Account
{
private:
    int maturityDate = 21;
    int fixedInterestRate = 0.25;
    int date;
    int a;
public:
    FixedDepositAccount(int an, int b, string name, int date) : Account(an, b, name) , date(date){}

    void calculateInterest()
    {
        if(date > maturityDate)
        {
            a = balance * fixedInterestRate;
            balance = balance - a;
            cout << "New Balance After " << maturityDate << " / 05 / 2025: " << balance << endl; 
        }
    }
    void printStatement()
    {
        cout << "Transition history " << endl;
        cout << "Total amount Withdraw: " << Withdraw << endl;
        cout << "Current Balance: " << balance << endl;
        cout << "Maturity Date: " << maturityDate << " / 05 / 2025 " << endl;
        cout << "Fixed Interest Rate: 25 % "<< endl;
    }

};

int main()
{
    Account *a1;
    SavingAcount s1(111000223,2500,"Zain",25,1000);

    a1 = &s1;
    a1->calculateInterest();
    a1->printStatement();
    cout << "------------------" << endl;
    FixedDepositAccount fd1(111223,3500,"Imaad",30);
    a1 = &fd1;
    a1->withdraw(2500);
    a1->calculateInterest();
    a1->printStatement();

}
