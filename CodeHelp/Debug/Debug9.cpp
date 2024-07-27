#include <iostream>
using namespace std;

class Base {
public:
    Base(int x) : value(x) {}
    void display() { cout << "Base: " << value << endl; }
private:
    int value;
};

class Derived : public Base {
public:
    Derived(int y) : Base(y) {}
//     void show() { cout << "Derived: " << value << endl; }
// private:
//     int value;
};

int main() {
    Base* ptr = new Derived(10);
    ptr->display();
    // ptr->show();
    delete ptr;
    return 0;
}