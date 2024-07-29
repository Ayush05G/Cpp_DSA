#include <bits/stdc++.h>
using namespace std;

//Approach 1(O(n))
class Solution{
public:
    Shop shop;

    Solution(Shop s) {
        this->shop = s;
    }

    long long find(int n, long k) {
        long long count = 0;

        // Iterate over the prices from cheapest to most expensive
        for (int i = n - 1; i >= 0; --i) {
            long price = shop.get(i);
            if (price <= k) {
                count += k / price;  // Buy as many chocolates as possible at this price
                k %= price;          // Update remaining money
            }
        }

        return count;
    }
};