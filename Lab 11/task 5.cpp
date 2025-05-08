#include "iostream"
#include <exception>
using namespace std;

class InsufficientFundsException{
    public:
    const char* what() const noexcept
    {
        return "InsufficientFundsException - Deficit: $ ";
    }
};
template<typename T>
class BankAccount{
    private:
    T balance;

    public:
    BankAccount(T b) : balance(b){}
    T getBalance()
    {
        return balance;
    }
    void withdraw(T amount)
    {
        if(amount > balance)
        {
            throw InsufficientFundsException();
        }
        else
        {
            cout << "Withdraw success amount: $" << amount << endl;
            cout << "Remaining: $" << balance - amount << endl;
        }
    }
};

int main()
{
    int amount = 250;
    int amount2 = 1100;
    BankAccount ba(1000);
    cout << "Balance: $" << ba.getBalance() << endl;
    try{
        ba.withdraw(amount);
    }
    catch(const InsufficientFundsException& e)
    {
        cout << e.what() << endl;
        cout << amount - ba.getBalance() << endl;
        
    }
    cout << endl;
    cout << "Balance: $" << ba.getBalance() << endl;
    try{
        ba.withdraw(amount2);
    }
    catch(const InsufficientFundsException& e)
    {
        cout << "Withdraw: $" << amount2 << ": " << e.what();
        cout << amount2 - ba.getBalance() << endl;
        
    }
}
