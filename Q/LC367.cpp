class Solution {
public:
    // Function to check if a given number is a perfect square
    bool isPerfectSquare(int num) {
        long left = 1;            // Initializing the lower boundary of the search space
        long right = num;         // Initializing the upper boundary of the search space

        // Using binary search to find the square root of the number
        while (left < right) {    
            long mid = left + (right - left) / 2; // Calculating the mid-value to prevent overflow
            // If mid squared is greater than or equal to num, we narrow down the upper boundary
            if (mid * mid >= num) {
                right = mid;
            } else {
                // If mid squared is less than num, we narrow down the lower boundary
                left = mid + 1;
            }
        }

        // Once left and right converge, we verify if the number is indeed a perfect square
        return left * left == num;
    }
};
