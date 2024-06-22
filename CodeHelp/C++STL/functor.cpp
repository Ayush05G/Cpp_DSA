#include<iostream>
using namespace std;

class functorOne {
    public:
        bool operator()(int a, int b) {
            ///descending order me cmp karna chahte ho
            // if  a>b -> true, a should be placed before b
            // that's why descending order banata h
            return a > b;
        }
};

int main() {

    functorOne cmp;

    if( cmp(10,5 ) == true ) {
        cout << "10 is greater than 5" << endl; 
    }
    else {
        cout << "10 is less than 5";
    }


    return 0;
}