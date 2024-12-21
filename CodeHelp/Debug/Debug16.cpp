#include <bits/stdc++.h>
using namespace std;

/*
Determine if a 9 x 9 Sudoku board is valid.
*/

bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> col(9, vector<int>(9, 0));
        vector<vector<int>> mat(9, vector<int>(9, 0));
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && (row[i][board[i][j] - '1'] == 1 || col[j][board[i][j] - '1'] == 1))
                    return false;

                if (board[i][j] != '.') {
                    row[i][board[i][j] - '1'] = 1;
                    col[j][board[i][j] - '1'] = 1;
                }

                int r = 3 * (i / 3) + (j / 3);
                if (board[i][j] != '.' && mat[r][board[i][j] - '1'] == 1) {
                    return false;
                }

                if (board[i][j] != '.') {
                    mat[r][board[i][j] - '1'] = 1;
                }
            }
        }
        return true;
    }

int main(){
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << isValidSudoku(board) << endl;
    return 0;
}