#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int rows, int cols) {
        if (rows * cols != original.size()) {
            return {};
        }
        vector<vector<int>> result(rows, vector<int>(cols));
      
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = original[i * cols + j];
            }
        }
        return result;
    }
};
