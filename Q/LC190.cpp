#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversedNumber = 0; // Initialize the result to represent the reversed number.
      
        // Loop through all 32 bits of the input number.
        for (int bitPosition = 0; bitPosition < 32; ++bitPosition) {
            // Isolate the least-significant bit (rightmost bit) of 'n' and shift it to the correct position
            // in 'reversedNumber' (which starts from the leftmost bit and goes rightwards with each iteration).
            reversedNumber |= (n & 1) << (31 - bitPosition);
            // Shift input number 'n' right by one bit to process the next bit in the next iteration.
            n >>= 1;
        }
      
        // Return the reversed number after all 32 bits have been processed.
        return reversedNumber;
    }
};
