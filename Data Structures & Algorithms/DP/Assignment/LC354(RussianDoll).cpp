class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort envelopes by width; if the same, then by height in decreasing order
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& env1, const vector<int>& env2) {
            return env1[0] < env2[0] || (env1[0] == env2[0] && env1[1] > env2[1]);
        });

        // Variable to store the number of envelopes
        int numEnvelopes = envelopes.size();

        // Dynamic Programming vector to store the increasing heights
        vector<int> heightSequence{ envelopes[0][1] };

        // Process each envelope
        for (int i = 1; i < numEnvelopes; ++i) {
            int currentHeight = envelopes[i][1];
            // If current envelope's height is greater than the last height in the sequence
            if (currentHeight > heightSequence.back()) {
                // Add the height to the sequence
                heightSequence.push_back(currentHeight);
            } else {
                // Find the first element in the sequence which is not less than currentHeight
                auto it = lower_bound(heightSequence.begin(), heightSequence.end(), currentHeight);
                // Update the sequence element with the currentHeight
                *it = currentHeight;
            }
        }
        // Return the size of the longest increasing height sequence
        return heightSequence.size();
    }
};