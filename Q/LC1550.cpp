#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int total=arr.size();
        int counter=0;
        for(int i=0;i<total;i++){
            if(arr[i]&1){
                counter++;
                if (counter>=3){
               return true;
                }
            }
            else
            counter=0;
        }
        return false;
    }
};