class Solution {
public:
    // Function to determine if the string can be made valid by swapping brackets
    bool canBeValid(string s, string locked) {
        int n = s.length(); // n is the length of the input string

        // If the length of the string is odd, it is not possible to have a valid set of brackets
        if (n % 2 != 0) { 
            return false;
        }

        // Forward scan: from the beginning to check if we can make a valid string
        int openBrackets = 0; // Track the balance of open brackets
        for (int i = 0; i < n; ++i) {
            // If the current character is an open bracket or it is unlocked, increase the count of open brackets
            // Unlocked characters '0' are treated as wildcards that can be either open or closed brackets
            if (s[i] == '(' || locked[i] == '0') {
                ++openBrackets;
            } 
            else if (openBrackets > 0) { // If it is a closed bracket and there is an open bracket available, balance it out
                --openBrackets;
            } 
            else {
                return false; // If there is no open bracket available to balance the close, it is invalid
            }
        }

        // Backward scan: from the end to check if we can make a valid string
        int closeBrackets = 0; // Track the balance of close brackets
        for (int i = n - 1; i >= 0; --i) {
            // If the current character is a closed bracket or it is unlocked, treat it similarly to the forward scan
            if (s[i] == ')' || locked[i] == '0') {
                ++closeBrackets;
            } 
            else if (closeBrackets > 0) { // If there is a close bracket available to balance the open, balance it out
                --closeBrackets;
            } 
            else {
               return false; // If there is no close bracket available to balance the open bracket, it is invalid
            }
        }

        // If both scans do not detect an imbalance, the string can be made valid
        return true;
    }
};