#include <iostream>
using namespace std;

class Vehicle 
{
    protected:
    static int vehicleID;
    int ID;
    static int activeDeliveries;

    public:
    Vehicle() 
    {
        ID = vehicleID++; 
        activeDeliveries++; 
    }
    virtual ~Vehicle() 
    { 
        activeDeliveries--; 
    }
    int getID()
    {
        return ID;
    }
    virtual void deliveryRoute() 
    {
        cout << "Optimal delivery route calculated for vehicle " << getID() << endl;
    }
    virtual void deliveryTime() 
    {
        cout << "Estimated delivery time calculated for vehicle " << getID() << endl;
    }
    virtual void command(string cmd, int packageID) 
    {
        cout << "Executing " << cmd << " for package " << packageID << endl;
    }
    virtual void command(string cmd, int packageID, string urgency) 
    {
        cout << "Executing " << cmd << " for package " << packageID << " with urgency: " << urgency << endl;
    }
    
    friend bool compareEfficiency(const Vehicle& v1, const Vehicle& v2);
    virtual bool operator==(Vehicle& other) 
    {
        return this->getID() == other.getID(); 
    }
};

int Vehicle::activeDeliveries = 0;

class RamzanDrone : public Vehicle 
{
    public:
    RamzanDrone(){}
    void deliveryRoute() 
    {
        cout << "Aerial route calculated for drone " << getID() << endl;
    }
    void command(string cmd, int packageID, string urgency) 
    {
        cout << "Drone " << getID() << " executing " << cmd << " with high-speed mode for " << urgency << endl;
    }
};

class RamzanTimeShip : public Vehicle 
{
    public:
    RamzanTimeShip(){}
    void deliveryRoute() 
    {
        cout << "Time-travel route verified for TimeShip " << vehicleID << endl;
    }
    void command(string cmd, int packageID, string urgency)
    {
        cout << "TimeShip " << getID() << " validating historical accuracy for " << urgency << endl;
    }
};

class RamzanHyperPod : public Vehicle 
{
    public:
    RamzanHyperPod() {}
    void deliveryRoute()  
    {
        cout << "Underground tunnel path optimized for HyperPod " << getID() << endl;
    }
};

bool compareEfficiency( Vehicle& v1, Vehicle& v2) 
{
    return v1.getID() < v2.getID(); 
}

int Vehicle::vehicleID = 100;
int main() 
{
    cout << "-----------------------------------" << endl;
    cout << "Muhammad Hammad-24K-0544" << endl;
	cout << "-----------------------------------\n" << endl;
    RamzanDrone d1;
    RamzanTimeShip t1;
    RamzanHyperPod h1;

    d1.command("Deliver", 1001, "Iftar");
    t1.command("Deliver", 1002, "Sehri");
    h1.command("Return",3001,"Sheri");
    h1.deliveryRoute();

    return 0;
}

