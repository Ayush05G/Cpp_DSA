#include <iostream>
#include <algorithm>
#include<cmath>
#include<limits.h>
#include <vector>
#include<string>
using namespace std;

void fillPrimes(vector<int>& prime, int high)
{
    vector<bool> ck(high+1, true);
    for (int i = 2; (i * i) <= high; i++) {
        if (ck[i] == true) {
            for (int j = i * i; j <= sqrt(high); j = j + i) {
                ck[j] = false;
            }
        }
    }
    for (int i = 2; i * i <= high; i++) {
        if (ck[i] == true) {
            prime.push_back(i);
        }
    }
}

void segmentedSieve(int low, int high)
{
    if (low<2 and high>=2){
        low = 2;
    }
    vector<bool> prime(high-low+1, true);
    vector<int> chprime;
    fillPrimes(chprime, high);
    for (int i : chprime) {
        int lower = (low / i);
        if (lower <= 1) {
            lower = i + i;
        }
        else if (low % i) {
            lower = (lower * i) + i;
        }
        else {
            lower = (lower * i);
        }
        for (int j = lower; j <= high; j = j + i) {
            prime[j-low] = false;
        }
    }
   
    for (int i = low; i <= high; i++) {
        if (prime[i-low] == true) {
            cout << (i) << " ";
        }
    }
}

int main(){
    int low = 10, high = 50;
    segmentedSieve(low, high);
    return 0;
}