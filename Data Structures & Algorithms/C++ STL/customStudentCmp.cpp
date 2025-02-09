#include<iostream>
#include<vector>
#include<algorithm>
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

class comparator{
public:     
    bool operator()(Student a, Student b) {
        if(a.marks == b.marks) {
            return a.name < b.name;
        }
        return a.marks > b.marks;
    }
};

int main() {
    vector<Student> arr;
    arr.push_back(Student(90,"Love"));
    arr.push_back(Student(90, "Laksay"));
    arr.push_back(Student(95,"Kunal"));

    sort(arr.begin(), arr.end(), comparator());

    for(Student a: arr) {
        cout << a.marks << " " << a.name << endl;
    }



    return 0;
}