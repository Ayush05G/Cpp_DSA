#include <iostream>
#include<algorithm>
#include<limits.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int naive(vector<int> &nums)
    {
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum = sum + nums[j]; // saare subarrays ka
                                     // sum nikalega, with nums[i] as pivot.
                ans = max(ans, sum);
                // if(sum > ans)
                //     ans = sum;
            }
        }
        return ans;
    }

    // famous algo // TC: O(n)
    int kadaneAlgo(vector<int> &nums)
    {
        int ans = INT_MIN, sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            sum += num;
            ans = max(ans, sum);
            if (sum < 0)
                sum = 0;
        }
        return ans;
    }

    int maxSubArray(vector<int> &nums)
    {
        // return naive(nums);

        return kadaneAlgo(nums);
    }
};