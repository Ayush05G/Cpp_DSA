#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers of size N, you have to divide it into the minimum number of ā€strictly increasing subsequences.
Take the following example where the sequence is {1, 3, 2, 4}, then the answer would be 2. The first increasing sequence would be {1, 3, 4} and the second would be {2}.
*/

int MinimumNumIncreasingSubsequences(int arr[], int n)
{
    multiset<int> last;
    for (int i = 0; i < n; i++) {
        multiset<int>::iterator it = last.lower_bound(arr[i]);
        if (it == last.begin())
            last.insert(arr[i]);
        else {
            it--;
            last.erase(it);
            last.insert(arr[i]);
        }
    }
    return last.size();
}

int main() 
{ 
    int arr[] = {1, 3, 2, 4}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << MinimumNumIncreasingSubsequences(arr, n) << endl; 
    return 0; 
}