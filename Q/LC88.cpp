#include <bits/stdc++.h>
using namespace std;

//First Approach
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;      
    int j = n - 1;      
    int k = m + n - 1;

    while (j >= 0)
      if (i >= 0 && nums1[i] > nums2[j])
        nums1[k--] = nums1[i--];
      else
        nums1[k--] = nums2[j--];
  }
};

//Second Approach
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int k = 0;

        // Merge logic using two pointers
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                nums1[k] = nums1[i];
                i++;
            } else {
                nums1[k] = nums2[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements from nums1 if any
        while (i < m) {
            nums1[k] = nums1[i];
            i++;
            k++;
        }

        // Copy remaining elements from nums2 if any
        while (j < n) {
            nums1[k] = nums2[j];
            j++;
            k++;
        }
    }
};

