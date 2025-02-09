#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Converts a string s to its "transformed" value as per the problem statement
    // and performs the transformation k times.
    int getLucky(string s, int k) {
        string transformed; // Holds the numeric representation of the string 's'
      
        // Convert each character in string 's' to its corresponding number
        // 'a' -> 1, 'b' -> 2, ..., 'z' -> 26
        for (char c : s) {
            transformed += to_string(c - 'a' + 1);
        }
      
        // Perform k transformations
        while (k--) {
            int sumDigits = 0; // Placeholder for the sum of digits
          
            // Calculate the sum of the digits in the transformed string
            for (char digitChar : transformed) {
                sumDigits += digitChar - '0'; // Convert char to int and add to sum
            }
          
            // Update the transformed string to the new value
            transformed = to_string(sumDigits);
        }
      
        // Finally, convert the transformed string to an integer and return it
        return stoi(transformed);
    }
};
