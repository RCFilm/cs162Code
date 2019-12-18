#include <iostream>

using namespace std;

class Circle {
public:
    //STATE/PROPERTIES
    double radius;
    double x;
    double y;

    //CONSTRUCTORS
    Circle() {
        radius = 2;
        x = 0;
        y = 0;
    }

    Circle(double theRadius) {
        radius = theRadius;
        x = 0;
        y = 0;
    }

    Circle(double theRadius, double xLoc, double yLoc) {
        radius = theRadius;
        x = xLoc;
        y = yLoc;
    }

    //BEHAVIORS
    double getArea() {
        return radius * radius * 3.14;
    }

    void print() {
        cout << "Circle with a radius of " << radius << endl
             << "    centered at " << x << ", " << y;
    }

};

int main()
{
    Circle c1;
    c1.print();

    //can directly change public members:
    c1.radius = 10;
    c1.print();

    Circle c2(4, 12, 3);
    c2.print();

    return 0;
}

