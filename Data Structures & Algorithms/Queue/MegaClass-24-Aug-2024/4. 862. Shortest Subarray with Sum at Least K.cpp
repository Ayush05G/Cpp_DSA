class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int K)
    {
        int n = nums.size();
        vector<long long> P(n, 0); // Prefix sum array of size n

        // Compute the prefix sum array directly
        P[0] = nums[0];
        for (int i = 1; i < n; ++i)
            P[i] = P[i - 1] + nums[i];

        deque<int> dq;
        int minLength = INT_MAX;

        for (int j = 0; j < n; ++j)
        {
            // If the current prefix sum itself is greater than or equal to K
            if (P[j] >= K)
                minLength = min(minLength, j + 1);

            // Try to find the smallest i such that P[j] - P[i] >= K
            while (!dq.empty() && P[j] - P[dq.front()] >= K)
            {
                minLength = min(minLength, j - dq.front());
                dq.pop_front();
            }

            // Maintain increasing order of prefix sums
            // ensures that when we subtract an earlier prefix sum from later one, we 
            // are getting the largest possible difference.
            while (!dq.empty() && P[j] <= P[dq.back()])
                dq.pop_back();

            // Add current index to deque
            dq.push_back(j);
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};