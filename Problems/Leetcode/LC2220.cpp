class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff = start ^ goal;
        int flipCount = 0;
      
        while (diff) {
            // If the least significant bit is 1, it needs to be flipped
            flipCount += diff & 1;
          
            // Right shift diff to check the next bit in the next iteration
            diff >>= 1;
        }
        return flipCount;
    }
};