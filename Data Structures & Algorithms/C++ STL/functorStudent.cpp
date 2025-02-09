#include<iostream>
using namespace std;

class Student{
    public:
        int marks;
        string name;
        Student() {

        }
        Student(int m, string n) {
            this->marks = m;
            this->name = n;
        }
};

//functor
class StudentComparator{
    public:
        bool operator()(Student a, Student b) {
            return a.marks < b.marks;
        }

};


int main() {

    Student s1;
    Student s2;

    s1.marks = 93;
    s1.name = "love";

    s2.marks = 97;
    s2.name = "lakshay";

    StudentComparator cmp;

    if( cmp(s1,s2) ) {
        cout << "love k marks lakshay se kam hai";
    }
    else {
        cout << "lakshay k marks love se kam hai";
    }





    return 0;
}