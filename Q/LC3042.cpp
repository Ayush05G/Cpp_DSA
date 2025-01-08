class Solution {
public:
    // Function to count the number of pairs of strings in the given vector 'words'
    // where one string is a prefix as well as a suffix of the other string.
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;                     // Initialize the count of valid pairs
        int numWords = words.size();       // Get the number of words in the vector
        // Iterate over each word in the vector as the potential prefix/suffix
        for (int i = 0; i < numWords; ++i) {
            string prefixSuffix = words[i];      
            // Iterate over the remaining words in the vector to find a match
            for (int j = i + 1; j < numWords; ++j) {
                string candidate = words[j]; 
                // Check that the word at index i is a prefix of the word at index j
                if (candidate.find(prefixSuffix) == 0 &&
                    // Additionally check that it is also a suffix of the word at index j
                    candidate.rfind(prefixSuffix) == candidate.length() - prefixSuffix.length()) {
                    count++;    // If both prefix and suffix conditions are satisfied, increment count
                }
            }
        }
        return count; // Return the total count of valid prefix and suffix pairs
    }
};
