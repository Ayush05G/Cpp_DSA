#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, int>> arr;
        
        // Populate arr with pairs (heights[i], i)
        for (int i = 0; i < n; ++i) {
            arr.emplace_back(heights[i], i);
        }
        
        // Sort arr based on the first element of each pair (heights)
        sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        
        // Create the result vector using the sorted indices
        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(names[arr[i].second]);
        }
        
        return ans;
    }
};