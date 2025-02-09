#include<bits/stdc++.h>

class Solution {
public:
    int helper(int n){
        if(n==0) return 1;
        if(n<0) return 0;
        int ans=INT_MAX;
        int i=1;
        int end=sqrt(n);
        while(i<=end){
            int square=i*i;
            int number=1+helper(n-square);
            if(number<ans)
            ans=number;
            ++i;
    }  
    return ans;  
    }

    int numSquares(int n) {
        return helper(n)-1;
    }
};