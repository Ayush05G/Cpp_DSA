class Solution {
public:
    int trap(vector<int>& height) {
        int num_elements = height.size(); // Number of elements in the height vector
      
        // Handling edge case: if the height vector is empty or has only one bar,
        // no water can be trapped.
        if(num_elements < 2) {
            return 0;
        }
      
        vector<int> left_max(num_elements), right_max(num_elements); // Initialize vectors to store the max height to the left and right of each element
      
        // Base case: The first element's left max will be itself and
        // the last element's right max will be itself
        left_max[0] = height[0];
        right_max[num_elements - 1] = height[num_elements - 1];
      
        // Fill left_max array such that left_max[i] contains highest bar height to the left of index 'i' including itself
        for (int i = 1; i < num_elements; ++i) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }
      
        // Fill right_max array such that right_max[i] contains highest bar height to the right of index 'i' including itself
        for (int i = num_elements - 2; i >= 0; --i) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }
      
        int total_water = 0; // Initialize total water to be trapped
      
        // Calculate trapped water at each index 'i' by finding the
        // smaller of the left and right max bars and subtracting the current height.
        // The result is added to total_water to find the cumulative water trapped across the entire array.
        for (int i = 0; i < num_elements; ++i) {
            total_water += min(left_max[i], right_max[i]) - height[i];
        }
      
        // Return the total amount of trapped water
        return total_water;
    }
};