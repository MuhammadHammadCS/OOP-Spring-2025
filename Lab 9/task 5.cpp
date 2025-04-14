#include "iostream"
using namespace std;

class Activity{
    protected:
    virtual float calculateCaloriesBurned() = 0;
};

class Running : public Activity{
    private:
    double distance;
    double time;
    public:
    Running(double dis, double t)
    {
        distance = dis;
        time = t;
    }
    float calculateCaloriesBurned(){
        return distance *(time/60)*62;
    }
};

class Cycling : public Activity{
    private:
    double speed;
    double time;
    public:
    Cycling(double sp, double t)
    {
        speed = sp;
        time = t;
    }
    float calculateCaloriesBurned(){
        return  (time*62)/speed;
    }
};

int main()
{
    Running run(60,100);
    Cycling cycle(25,4);

    cout << "Calories Burned in Running: " << run.calculateCaloriesBurned() << endl;
    cout << "Calories Burned in Cycling: " << cycle.calculateCaloriesBurned() << endl;
    
}
