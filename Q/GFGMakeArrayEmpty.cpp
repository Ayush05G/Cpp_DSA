class Solution {
public:
    int minimumTime(vector<int> arr) {
        int operations = 0;
        while (!arr.empty()) {
            // If first element is minimum, just remove it
            if (arr[0] == *min_element(arr.begin(), arr.end())) {
                arr.erase(arr.begin());
            }
            // Otherwise, remove first element and append to end
            else {
                int firstElement = arr[0];
                arr.erase(arr.begin());
                arr.push_back(firstElement);
            }
            operations++;
        }
        return operations;
    }
};