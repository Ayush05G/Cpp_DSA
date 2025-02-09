class Solution {
public:
    bool isPowerOfFour(int n) {
    if (n <= 0) {
        return false; // 0 and negative numbers are not powers of four
    }
    if (n == 1) {
        return true; // 4^0 = 1
    }
    if (n % 4 != 0) {
        return false; // Odd numbers greater than 1 are not powers of four
    }
    return isPowerOfFour(n / 4);
}
};