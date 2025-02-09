#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int numRows = matrix.size(); 
        int numCols = matrix[0].size(); 
        vector<int> minInRows(numRows, INT_MAX); 
        vector<int> maxInCols(numCols, INT_MIN); 
      
        // Find the minimum value in each row and the maximum value in each column
        for(int i = 0; i < numRows; ++i) {
            for(int j = 0; j < numCols; ++j) {
                minInRows[i] = min(minInRows[i], matrix[i][j]);
                maxInCols[j] = max(maxInCols[j], matrix[i][j]);
            }
        }  
        vector<int> luckyNumbers;
        for(int i = 0; i < numRows; ++i) {
            for(int j = 0; j < numCols; ++j) {
                if(matrix[i][j] == minInRows[i] && matrix[i][j] == maxInCols[j]) {
                    luckyNumbers.push_back(matrix[i][j]);
                }
            }
        }
       return luckyNumbers;
    }
};