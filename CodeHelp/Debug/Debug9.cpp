#include <iostream>
using namespace std;

class Shape {
public:
    Shape(int s) : sides(s) {}
    virtual void draw() { cout << "Drawing a shape with " << sides << " sides." << endl; }
private:
    int sides;
};

class Circle : public Shape {
public:
    Circle(int r) : Shape(0), radius(r) {}
//     void draw() { cout << "Drawing a circle with radius " << radius << "." << endl; }
private:
    int radius;
};

int main() {
    Shape* s = new Circle(5);
    s->draw();
    delete s;
    return 0;
}