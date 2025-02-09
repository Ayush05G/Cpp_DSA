#include<bits/stdc++.h>
using namespace std;

//Approach 1(O(n^2))
class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        int length=arr.size();
        int dominant=0;
        for(int i=0;i<length/2;i++){
            for(int j=length/2;j<length;j++){
                if (arr[i]>=5*arr[j])
                dominant+=1;
            }
        }
        return dominant;
        // Code here
    }  
};

//Approach 2(O(nlogn))
class Solution {
public:
    int dominantPairs(int n, vector<int> &arr) {
        int length = arr.size();
        int dominant = 0;

        // Sort the first and second halves of the array
        sort(arr.begin(), arr.begin() + length / 2);
        sort(arr.begin() + length / 2, arr.end());

        int j = length / 2;
        for (int i = 0; i < length / 2; i++) {
            while (j < length && arr[i] >= 5 * arr[j]) {
                j++;
            }
            dominant += (j - length / 2);
        }

        return dominant;
    }
};