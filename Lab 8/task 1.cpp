#include "iostream"
using namespace std;

class Humidity;
class Temperature{
    private:
    float temp;
    public:
    Temperature(float tp) : temp(tp){}

    friend void calculateHeatIndex(Temperature T, Humidity H);
};

class Humidity{
    private:
    float humid;
    public:
    Humidity(float hd) : humid(hd) {}
    friend void calculateHeatIndex(Temperature T, Humidity H);
};

void calculateHeatIndex(Temperature T, Humidity H)
{
    float value;
    value = -42.379 + 2.04901523 * T.temp + 10.14333127 * H.humid - 0.22475541 * T.temp * H.humid;
    cout << "Heat Index: " << value << endl;
}

int main()
{
    Temperature t(32.0);
    Humidity h(70.0);
    calculateHeatIndex(t,h);
}
