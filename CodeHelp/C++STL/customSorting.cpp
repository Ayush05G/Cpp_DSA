#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class comparator{
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {

    vector<int> arr;

    arr.push_back(20);
    arr.push_back(10);
    arr.push_back(15);

    //ascending order
    sort(arr.begin(), arr.end(),comparator());

    //print
    for(int a: arr) {
        cout << a << " ";
    }
    cout << endl;



    return 0;
}