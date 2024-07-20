class Solution {
public:
    bool isSafe(char digit, int row, int col,vector<vector<char>>& board) {
        //3 rule
        //rowCheck
        int n = board.size();
        for(int k=0; k<n; k++) {
            if(board[row][k] == digit) {
                //same digit pehel se same row me exist krta h 
                return false;
            }
        }   
        //colCheck
        for(int k=0; k<n; k++) {
            if(board[k][col] == digit) {
                //same col me same digit pehle se exist kta h 
                return false;
            }
        }
        //3*3 Sub-box check 
        for(int k=0; k<n; k++) {
            if(board[3*(row/3)+k/3][3*(col/3)+k%3] == digit) {
                //same 3*3 k box me same digit exist krta h 
                return false;
            }
        }
        //agar teeno rules badia follow ho rhe h toh kya krna h 
        return true;

    }
    bool solve(vector<vector<char>>& board) {
        //entire logic 
        //base case - ?

        //1 case hum solve karenge , baaki recursion sambhal lega 
        //sabse pehle find the empty cell
        //empty -> '.'
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                //main i,j wali cell pr aagya 
                //pr pata kaise lagegak data fill karu ya nahi
                //sirf empty cell pr fill krenge
                if(board[i][j] == '.' ) {
                    //fill this cell, coz its empty 
                    ///empty cell pr mujhe 1 -> 9 tk digit hit and trial krne hai
                    for(char digit='1'; digit<='9'; digit++) {
                        //konsa digit rakh skta hu, ye kaise pta lagega
                        //mujhe bs check krna h, k konsa digit rakhna safe hai 
                        if(isSafe(digit,i,j, board) == true) {
                            //agar safe hai rakhna 
                            board[i][j] = digit;
                            //baaki kon sambhalega -> recursion
                            bool aageSolveHoPaya = solve(board);
                            if(aageSolveHoPaya == true) {
                                //pooora board solve hogya 
                                return true;
                            }
                            else {
                                //ye vo case h -> jaha tumne ek digit place krdi h but recursion se aage ka answer false aagya 
                                //age board solve nahi ho paya 
                                //backtrack -> shayad maine galat digit rakh dia 
                                board[i][j] = '.';
                            }
                        }
                    }
                    //agar aap yaha pohoch gye 
                    //iska mtlab ye h-> k 1->9 tk koi bhi digit yaha pr fit nahi ho rha 
                    //pichle kahin pr galti kari h 
                    return false;
                }
            }
        }
        //yaha aagye -> iska matlab
        //board -> completely fille hogya h 
        //ans aa chuka h
        return true;

    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};