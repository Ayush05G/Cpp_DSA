#include <iostream>
using namespace std;

class A {
public:
    virtual void display() { cout << "A" << endl; }
};

class B : public A {
public:
    void display() { cout << "B" << endl; }
};

class C : public B {
public:
    void display() { cout << "C" << endl; }
};

int main() {
    A* ptr = new C;
    ptr->display();
    delete ptr;
    return 0;
}