#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int ansIndex = -1;
        int n = arr.size();
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
    
        while(s <= e) {
            int number = arr[mid];
            int index = mid;
            int diff = number - index;
            if(diff == 0) {
                //right me ans milega
                s = mid+1;
            }
            else if(diff == 1) {
                //store and compute
                ansIndex = index;
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }
        //ye mujhse galat hogya tha 
        //for extreme right element missing case, we 
        //are hardcoding the logic below
        if(ansIndex == -1) {
            return n;
        }
        return ansIndex;
    }
};