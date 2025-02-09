class Solution {
public:
    bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false; // 0 and negative numbers are not powers of two
    }
    if (n == 1) {
        return true; // 2^0 = 1
    }
    if (n % 2 != 0) {
        return false; // Odd numbers greater than 1 are not powers of two
    }
    return isPowerOfTwo(n / 2);
}
};