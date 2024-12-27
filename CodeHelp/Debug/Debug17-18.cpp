#include <bits/stdc++.h>
using namespace std;

/*
Given an array, the task is to find sum of maximum sum alternating subsequence starting with first element. Here alternating sequence means first decreasing, then increasing, then decreasing, â€¦ For example 10, 5, 14, 3 is an alternating sequence. 
*/


int maxAlternateSum(int arr[], int n) 
{ 
    if (n == 1) 
        return arr[0]; 

    int min = arr[0]; 
    for (int i = 1; i < n; i++) { 
        if (min > arr[i]) 
            min = arr[i]; 
    } 
    if (min == arr[0]) { 
        return arr[0]; 
    } 

    int dec[n]; 
    memset(dec, 0, sizeof(dec)); 

    int inc[n]; 
    memset(inc, 0, sizeof(inc)); 

    dec[0] = inc[0] = arr[0]; 
  
    int flag = 0; 
    for (int i = 1; i < n; i++) { 
        for (int j = 0; j < i; j++) { 
            if (arr[j] > arr[i]) { 
                dec[i] = max(dec[i], inc[j] + arr[i]); 
                flag = 1; 
            } 
            else if (arr[j] < arr[i] && flag == 1) 
                inc[i] = max(inc[i], dec[j] + arr[i]); 
        } 
    } 
    int result = INT_MIN; 
    for (int i = 0; i < n; i++) { 
        if (result < inc[i]) 
            result = inc[i]; 
        if (result < dec[i]) 
            result = dec[i]; 
    } 
    return result; 
} 

int main() 
{ 
    int arr[] = { 8, 2, 3, 5, 7, 9, 10 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Sum of maximum sum alternating subsequence is "
         << maxAlternateSum(arr, n) << endl; 
    return 0; 
}