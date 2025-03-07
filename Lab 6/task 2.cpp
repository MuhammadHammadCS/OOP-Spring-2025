#include "iostream"
using namespace std;


class Vehicle
{
protected:
    string brand;
    int speed;

public:
    Vehicle(string brand, int speed) : brand(brand), speed(speed) {}

    void displaydetails()
    {
        cout << "----------------------------" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << " mph" << endl;
    }
};

class car : protected Vehicle
{
public:
    int seats;

    car(string brand, int speed, int seats) : Vehicle(brand, speed), seats(seats) {}

    void displaydetails()
    {
        Vehicle::displaydetails();
        cout << "Seats: " << seats << endl;
    }
};

class ElectricCar : public car
{
public:
    int batterylife;

    ElectricCar(string brand, int speed, int seats, int batterylife) : car(brand, speed, seats), batterylife(batterylife) {}

    void displaydetails()
    {
        car::displaydetails();
        cout << "Battery Life: " << batterylife << " kilowatt" << endl;
        cout << "----------------------------" << endl;
    }
};

int main()
{
    ElectricCar EC("Tesla", 280, 4, 3408);
    EC.displaydetails();
}
