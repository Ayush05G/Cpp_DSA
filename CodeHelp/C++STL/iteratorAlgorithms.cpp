#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


void printDouble(int a) {
    cout << 2*a << " ";
}

bool checkEven(int a) {
    return a%2 == 0;
}

int main() {

    vector<int> arr(6);
    arr[0] = 10;
    arr[1] = 11;
    arr[2] = 12;
    arr[3] = 13;
    arr[4] = 14;
    arr[5] = 15;


    auto it = partition(arr.begin(), arr.end(), checkEven);

    for(int a: arr) {
        cout << a << " ";
    }



    // auto it = unique(arr.begin(), arr.end());
    // //it iterator k phle saaare unique element hai
    // //it k baad saare duplicate element hai 
    // arr.erase(it, arr.end());
    // for(int a: arr) {
    //     cout << a << " ";
    // }


    // cout << "Before: " << endl;
    // for(int a: arr) {
    //     cout << a << " ";
    // }
    // cout << endl;
    // rotate(arr.begin(), arr.begin()+3, arr.end());
    // //HW -> left rotate ?
    // cout << "After: " << endl;
    // for(int a: arr) {
    //     cout << a << " ";
    // }
    // cout << endl;

    // sort(arr.begin(), arr.end());

    // for(int a: arr) {
    //     cout << a << " ";
    // }
    // cout << endl;
    // reverse(arr.begin(), arr.end());

    // for(int a: arr) {
    //     cout << a << " ";
    // }


    // int ans  = count_if(arr.begin(), arr.end(), checkEven);
    // cout << ans << endl;

    // int target = 11;
    // int ans = count(arr.begin(), arr.end(), target);
    // cout << ans << endl;

    // auto it = find_if(arr.begin(), arr.end(), checkEven);
    // cout << *it << endl;


    //for_each(arr.begin(), arr.end(),printDouble);
    // int target = 400;
    // auto it = find(arr.begin(), arr.end(), target);
    // cout << *it << endl;


    return 0;
}