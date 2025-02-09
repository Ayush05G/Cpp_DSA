#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    set<int> ans;
    int i = 0;  // nums1's index
    int j = 0;  // nums2's index

    while (i < nums1.size() && j < nums2.size())
      if (nums1[i] < nums2[j]) {
        ++i;
      } else if (nums1[i] > nums2[j]) {
        ++j;
      } else {
        ans.insert(nums1[i]);
        ++i;
        ++j;
      }

    return vector<int>(ans.begin(), ans.end());
  }
};