class Solution {
public:
    bool isPowerOfThree(int n) {
    if (n <= 0) {
        return false; // 0 and negative numbers are not powers of three
    }
    if (n == 1) {
        return true; // 3^0 = 1
    }
    if (n % 3 != 0) {
        return false; // Odd numbers greater than 1 are not powers of three
    }
    return isPowerOfThree(n / 3);
}
};