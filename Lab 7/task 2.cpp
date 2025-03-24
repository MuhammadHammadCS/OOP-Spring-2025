#include "iostream"
using namespace std;

class Shape{
    public:
    int position;
    string color;
    float borderthickness;
    
    Shape(int p, string c, float bt) : position(p) , color(c) , borderthickness(bt) {}
    virtual void draw()
    {
        return;
    }
    virtual int calculateArea()
    {
        return 1;
    }

    virtual int calculatePerimeter()
    {
        return 1;
    }
};

class Circle : public Shape{
    private:
    float radius;
    int centrePosition_x;
    int centrePosition_y;
    public:
    Circle(int p, string c, float bt) : Shape(p,c,bt)
    {
        cout << "Enter the radius for Circle: ";
        cin >> radius;
        cout << "Enter the Centre Position (X-axis): ";
        cin >> centrePosition_x;
        cout << "Enter the Centre Position (Y-axis): ";
        cin >> centrePosition_y;
    }

    void draw()
    {
        cout << "Circle drawn of Radius: " << radius << endl;
        cout << "With the Centre Position of: X: " << centrePosition_x << " Y: " << centrePosition_y << endl;
        cout << "OF Color: " << color << endl;
    }

    int calculateArea()
    {
        return radius*radius;
    }

    int calculatePerimeter()
    {
        return 2*3.14*radius;
    }   
};

class Rectangle : public Shape{
    private:
    int height;
    int width;
    int top_leftPos;
    public:
    Rectangle(int p, string c, float bt, int tlp) : Shape(p,c,bt) , top_leftPos(tlp){
        cout << "Enter the height: ";
        cin >> height;
        cout << "Enter the width: ";
        cin >> width;
    }
    void draw()
    {
        cout << "Rectangle Drawn with the height: " << height << " and Width: " << width << endl;
        cout << "Color of Rectangle: " << color << endl;
    }
    int calculateArea()
    {
        return height*width;
    }
    int calculatePerimeter()
    {
        return 2*height + 2*width;
    } 
};
int main()
{
    Shape *s1;
    Circle c1(2,"Brown", 1.5);
    s1 = &c1;
    s1->draw();
    cout << "The Area for Circle is: " << s1->calculateArea() << endl;
    cout << "The Perimeter for Circle is: " << s1->calculatePerimeter() << endl;
    cout << "----------------------" << endl;
    Rectangle r1(7,"Red",2.3,22);
    s1 = &r1;
    s1->draw();
    cout << "The Area for Rectangle is: " << s1->calculateArea() << endl;
    cout << "The Perimeter for Rectangle is: " << s1->calculatePerimeter() << endl;
}
