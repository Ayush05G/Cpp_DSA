#include<iostream>
using namespace std;

void findFirstOccurrence(int arr[], int n, int target, int &ansIndex) {
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s <= e) {
        if(arr[mid] == target) {
            //ans found -> may or may not be first occurence
            //store and compute
            ansIndex = mid;
            //kyoki first occurence ki baat hori h
            //toh batao left me jau first occ k liye ya right me 
            //left me jao
            e = mid - 1;
        }
        if(target > arr[mid] ) {
            ///right me jao
            s = mid + 1;
        }
        if(target < arr[mid]) {
            //left me jao 
            e = mid-1;
        }
        //ye main bhul jata hu
        mid = s + (e-s)/2;
    }
}

void findLastOccurrence(int arr[], int n, int target, int &ansIndex) {
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s <= e) {
        if(arr[mid] == target) {
            //target k equal toh hai
            //but may or may not be last occurrence
            //store and compute
            ansIndex = mid;
            //right me jao
            s = mid + 1;
        }
        if(target > arr[mid] ) {
            //right me jao
            s = mid+1;
        }
        if(target < arr[mid] ) {
            //left me jao 
            e = mid - 1;
        }
        //ye main bhul jata hu
        mid = s + (e-s)/2;
    }

}

int main() {

    int arr[] = {5,10,20,20,20,20,20,30,40,50,60};
    int n = 11;
    int target =20;
    //-1 means target not found
    int ansIndex = -1;
    //binary search lagane jaa ra hu, toh pkka array sorted hi hoga
        findFirstOccurrence(arr,n,target,ansIndex);
        cout << "First Occ index: " << ansIndex << endl;
        findLastOccurrence(arr,n,target,ansIndex);
        cout << "Last Occ index: " << ansIndex << endl;

    return 0;
}

// class Solution {
// public:
//     int missingNumber(vector<int>& arr) {
//         sort(arr.begin(), arr.end());

//         int ansIndex = -1;
//         int n = arr.size();
//         int s = 0;
//         int e = n-1;
//         int mid = s + (e-s)/2;
        
//         while(s <= e) {
//             int number = arr[mid];
//             int index = mid;
//             int diff = number - index;
//             if(diff == 0) {
//                 //right me ans milega
//                 s = mid+1;
//             }
//             else if(diff == 1) {
//                 //store and compute
//                 ansIndex = index;
//                 e = mid-1;
//             }
//             mid = s + (e-s)/2;
//         }
//         if(ansIndex == -1) {
//             return n;
//         }
//         return ansIndex;
//     }
// };