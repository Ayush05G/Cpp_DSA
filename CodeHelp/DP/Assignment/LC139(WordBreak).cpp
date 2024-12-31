class Solution {
public:
//     bool check(vector<string>& wordDict, string& s) {
//         for (auto i : wordDict) {
//             if (s == i) return true;
//         }
//         return false;
//     }

//     bool solve(string& s, vector<string>& wordDict, int start, vector<int>& memo) {
//         if (start == s.size()) return true; // Reached the end of the string

//         if (memo[start] != -1) return memo[start]; // Return cached result

//         string word = "";
//         for (int i = start; i < s.size(); ++i) {
//             word += s[i];
//             if (check(wordDict, word) && solve(s, wordDict, i + 1, memo)) {
//                 return memo[start] = true;
//             }
//         }

//         return memo[start] = false; // Cache and return the result
//     }

//     bool wordBreak(string s, vector<string>& wordDict) {
//         vector<int> memo(s.size(), -1); // Memoization table initialized to -1
//         return solve(s, wordDict, 0, memo);
//     }
// };

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end()); // Use a set for faster lookups
        int n = s.size();
        vector<bool> dp(n + 1, false); // DP array where dp[i] means s[0:i] can be segmented

        dp[0] = true; // Base case: empty string can always be segmented

        // Iterate over all lengths of the substring
        for (int i = 1; i <= n; ++i) {
            // Check all possible breaks for the substring s[0:i]
            for (int j = 0; j < i; ++j) {
                // If s[0:j] can be segmented and s[j:i] is in the dictionary
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break; // No need to check further
                }
            }
        }

        return dp[n]; // The answer is whether the full string can be segmented
    }
};