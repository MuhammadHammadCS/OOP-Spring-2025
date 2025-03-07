#include "iostream"
using namespace std;

class Device
{
protected:
    int deviceID;
    bool status;

public:
    Device(int deviceID, bool status) : deviceID(deviceID), status(status) {}

    void displayDetails()
    {
        cout << "Device ID: " << deviceID << endl;
        if(status == true)
        {
            cout << "Status: On" << endl;
        }
        else
        {
            cout << "Status: Off" << endl;
        }
        
    }
};

class SmartPhone : protected Device
{
protected:
    float screensize;

public:
    SmartPhone(int deviceID, bool status, float screensize) : Device(deviceID, status), screensize(screensize) {}

    void displayDetails()
    {
        Device ::displayDetails();
        cout << "Screen Size: " << screensize <<  " inch" << endl;
    }
};
class SmartWatch : protected SmartPhone
{
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int deviceID, bool status, float screensize, bool heartRateMonitor) : SmartPhone(deviceID, status, screensize), heartRateMonitor(heartRateMonitor) {}

    void displayDetails()
    {
        SmartPhone ::displayDetails();
        if(heartRateMonitor == true)
        {
            cout << "Heart Rate Monitor: On" << endl;
        }
        else
        {
            cout << "Heart Rate Monitor: Off" << endl;
        }
        
    }
};

class SmartWearable : public SmartWatch
{
public:
    int stepCounter;

    SmartWearable(int deviceID, bool status, float screensize, bool heartRateMonitor, int stepCounter) : SmartWatch(deviceID, status, screensize, heartRateMonitor), stepCounter(stepCounter) {}

    void displayDetails()
    {
        SmartWatch ::displayDetails();
        cout << "Step Counter: " << stepCounter << endl;
    }
};
int main()
{
    SmartWearable sw(12344, true, 5.6, false, 50);
    sw.displayDetails();
    return 0;
}
