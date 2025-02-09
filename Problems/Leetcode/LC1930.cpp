class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // Initialize the count of palindromic subsequences to 0
        int countPaliSubseq = 0;

        // Iterate over all lowercase alphabets
        for (char c = 'a'; c <= 'z'; ++c) {
            // Find the first and last occurrence of the current character
            int firstIndex = s.find_first_of(c);
            int lastIndex = s.find_last_of(c);

            // Use an unordered set to store unique characters between the first and last occurrence
            unordered_set<char> uniqueChars;

            // Iterate over the characters between the first and last occurrence
            for (int i = firstIndex + 1; i < lastIndex; ++i) {
                // Insert unique characters into the set
                uniqueChars.insert(s[i]);
            }

            // Increment the count by the number of unique characters found
            countPaliSubseq += uniqueChars.size();
        }

        // Return the total count of palindromic subsequences
        return countPaliSubseq;
    }
};