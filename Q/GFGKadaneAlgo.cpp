#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to print the maximum contiguous subarray sum ending at each 
    //position in the array and return the overall maximum.
    long long maximumSum(int arr[], int sizeOfArray)
    {int sum=0;
    int ans=INT_MIN;
    for(int i=0;i<sizeOfArray;i++){
        if(sum<0)
        sum=0;
        sum+=arr[i];
        cout<<sum<<" ";
        ans=max(ans,sum);
    }
    cout<<endl;
    return ans;
       //code here
    }
};