class Solution {
public:
    unordered_map<int,bool> rowCheck;
    unordered_map<int,bool> lowerDiagnolCheck;
    unordered_map<int,bool> upperDiagnolCheck;

    void storeSolution(vector<vector<string>> &ans,vector<vector<char> > &board,int n ) {
        vector<string> tempAns;
        for(int i=0; i<n; i++) {
            string output = "";
            for(int j=0; j<n; j++) {
                output.push_back(board[i][j]);
            }
            //string is ready
            tempAns.push_back(output);
        }
        //vector of string is ready 
        ans.push_back(tempAns);
    }

    bool isSafe(int row, int col, vector<vector<char> > &board) {
        //brute for -> traverse board -> T.C -> n^2
        //Linear T.C -> 

        //check for row
        if(rowCheck[row] == true) {
            //not safe
            return false;
        }
        //check for upper diagnol
         if(upperDiagnolCheck[row-col] == true) {
            //not safe
            return false;
        }
        //check lower diagnol 
        if(lowerDiagnolCheck[row+col] == true) {
            //not safe
            return false;
        }  
        //else safe to place
        return true;
    }

    void solve(int n, vector<vector<char> > &board, vector<vector<string>> &ans, int col ) {
        //base case
        if(col >= n ) {
            //all queens are placed
            //store board arrangement in ans 
            storeSolution(ans, board, n);
            return;
        }
        //1 case hum solve karenge and baaki recursion
        //mere paas col ka index hai, uss column me konsi row me queen ko place krna h
        //vo yaha decide krre h 
        for(int row=0; row<n; row++) {
            //hr row pr queen ko place krke dekhunga 
            if(isSafe(row,col,board)) {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                lowerDiagnolCheck[row+col] = true;
                upperDiagnolCheck[row-col] = true;
                //baaki kon sambhalega
                //recursion
                solve(n,board,ans,col+1);
                //backtrack -> ye main bhul jata hu
                board[row][col] = '.';
                rowCheck[row] = false;
                lowerDiagnolCheck[row+col] = false;
                upperDiagnolCheck[row-col] = false;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        //board
        vector<vector<char> > board(n, vector<char>(n,'.'));
        //start placing Queen with 0th Column
        int col = 0;
        solve(n,board,ans,col);
        return ans;
    }
};