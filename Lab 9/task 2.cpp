#include "iostream"
using namespace std;

class SmartDevice{
    protected:
    virtual void turnON() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() = 0; 
};

class LightBulb : public SmartDevice{
    private:
    bool isOn;
    int brightness;

    public:
    LightBulb(bool on, int b)
    {
        isOn = on;
        brightness = b;
    }
    void turnON()
    {
        cout << "Light Bulb Turned On" << endl;
    }
    void turnOff()
    {
        cout << "Light Bulb Turned Off" << endl;
    }
    void getStatus(){
        if(isOn == true)
        {
            cout << "Is Light Bulb On: Yes" << endl;
        }
        else
        {
            cout << "Is Light Bulb On: No"<< endl;
        }
        cout << "Brightness: " << brightness << " %" << endl;
    }
};

class Thermostat : public SmartDevice{
    private:
    bool isOn;
    double temperature;

    public:
    Thermostat(bool on, double t)
    {
        isOn = on;
        temperature = t;
    }
    void turnON()
    {
        cout << "Thermostat Turned On" << endl;
    }
    void turnOff()
    {
        cout << "Thermostat Turned Off" << endl;
    }
    void getStatus(){
        if(isOn == true)
        {
            cout << "Is Thermostat On: Yes" << endl;
        }
        else
        {
            cout << "Is Thermostat On: No"<< endl;
        }        
        cout << "Brightness: " << temperature << " C" << endl;
    }
};

int main()
{
    LightBulb lb(true , 76);
    Thermostat ts(true , 110.7);
    cout << "-------------------------------" << endl;
    lb.turnON();
    lb.getStatus();
    lb.turnOff();
    cout << "-------------------------------" << endl;
    ts.turnON();
    ts.getStatus();
    ts.turnOff();
    cout << "-------------------------------" << endl;
}
