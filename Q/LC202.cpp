#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int isHappy(int n){
        if (n == 1 || n == 7) 
            return 1; 
        int sum = n, x = n; 
  
        // this loop executes till the sum of square of 
        // digits obtained is not a single digit number 
        while(sum > 9) { 
            sum = 0; 
  
            // this loop finds the sum of square of digits 
            while (x > 0) { 
                int d = x%10; 
                sum += d*d; 
                x/=10; 
            } 
            if (sum == 1) 
                return 1; 
            x = sum; 
        } 
        if(sum == 7) 
            return 1; 
        return 0;
    }
};