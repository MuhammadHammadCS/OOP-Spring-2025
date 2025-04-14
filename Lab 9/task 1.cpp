#include "iostream"
using namespace std;


class Vehicle{
    protected:
    string model;
    double rate;

    public:
    virtual double getDailyRate() = 0;
    virtual void displayDetails() = 0;
};

class Car : public Vehicle{
    public:
    Car(string m,double rt){
        model = m;
        rate = rt;
    }

    double getDailyRate(){
        return rate;
    }

    void displayDetails(){
        cout << "Model: " << model << endl;
        cout << "Rate: " << rate << endl;
    }
};

class Bike : public Vehicle{
    public:
    Bike(string m,double rt){
        model = m;
        rate = rt;
    }

    double getDailyRate(){
        return rate;
    }

    void displayDetails(){
        cout << "Model: " << model << endl;
        cout << "Rate: " << rate << endl;
    }
};

int main()
{
    Car c1("Toyota" , 33.33);
    Bike b1("Yamaha", 24.76);
    cout << endl;
    cout << "--------------------Car Details---------------" << endl; 
    c1.displayDetails();
    cout << "----------------------------------------------" << endl;
    cout << "Daily Car Rate: " << c1.getDailyRate();
    cout << endl;
    cout << "--------------------Bike Details---------------" << endl; 
    b1.displayDetails();
    cout << "----------------------------------------------" << endl;
    cout << "Daily Bike Rate: " << b1.getDailyRate();
}
