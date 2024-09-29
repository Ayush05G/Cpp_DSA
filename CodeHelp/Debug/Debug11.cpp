#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerElement(const vector<int>& nums) {
    stack<int> s;
    vector<int> result(nums.size(), -1);

    for (int i = 0; i < nums.size(); ++i) {
        while (!s.empty() && nums[i] < nums[s.top()]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

int main() {
    vector<int> nums = {5, 4, 3, 2, 1};
    vector<int> result = nextSmallerElement(nums);
    for (int num : result)
        cout << num << " ";
    return 0;
}