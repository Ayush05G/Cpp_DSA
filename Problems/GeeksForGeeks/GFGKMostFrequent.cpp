class Solution {
public:
    int kMostFrequent(int arr[], int n, int k) {
        // Create a frequency map
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        
        // Create a vector to store frequencies
        vector<int> frequencies;
        for (auto& entry : freq) {
            frequencies.push_back(entry.second);
        }
        
        // Sort frequencies in descending order
        sort(frequencies.begin(), frequencies.end(), greater<int>());
        
        // Sum the K most frequent element frequencies
        int total_freq = 0;
        for (int i = 0; i < k && i < frequencies.size(); i++) {
            total_freq += frequencies[i];
        }
        
        return total_freq;
    }
};