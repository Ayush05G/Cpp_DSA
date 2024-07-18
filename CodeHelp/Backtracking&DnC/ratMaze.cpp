//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int newx, int newy,vector<vector<int>> &m,vector<vector<bool>> &visited, int n ) {
        if(newx < 0 || newy < 0 || newx >=n || newy >= n ) {
            //out of bound
            return false;
        }
        if(visited[newx][newy] == true) {
            //already visited
            return false;
        }
        if(m[newx][newy] == 0) {
            //blocked space
            return false;
        }
        //valid case
        return true;
    }
    
    void solve(vector<vector<int>> &m,vector<vector<bool>> &visited, int n,vector<string> &ans,
                int curr_x, int curr_y, int destx,int desty, string output) {
        //base case
        if(curr_x == destx && curr_y == desty) {
            //rat reached destination
            //store output string ko ans me 
            ans.push_back(output);
            return;
        }
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        char move[] = {'U','D','L','R'};
        
        for(int i=0; i<4; i++) {
            int newx = curr_x + dx[i];
            int newy = curr_y + dy[i];
            char movement = move[i];
            
            if(isSafe(newx,newy,m,visited,n)) {
                visited[newx][newy] = true;
                output.push_back(movement);
                solve(m,visited,n,ans,newx,newy,destx,desty,output);
                //backtracking
                output.pop_back();
                visited[newx][newy] = false;
            }
            
        }
        
        
        //1 case hum solve karenge , baaki recursion sambhal lega
        //1 case -> up, down, left, right
        //UP
        //i,j -> i-1, j
        // int newx = curr_x-1;
        // int newy = curr_y;
        // if(isSafe(newx,newy,m,visited,n)) {
        //     visited[newx][newy] = true;
        //     output.push_back('U');
        //     solve(m,visited,n,ans,newx,newy,destx,desty,output);
        //     //wapas aaunga, toh visited toh revert krna padefga
        //     //backtracking
        //     output.pop_back();
        //     visited[newx][newy] = false;
        // }
        
        // //Down
        // //i,j -> i+1,j
        //  newx = curr_x+1;
        //  newy = curr_y;
        // if(isSafe(newx,newy,m,visited,n)) {
        //     visited[newx][newy] = true;
        //     solve(m,visited,n,ans,newx,newy,destx,desty,output+"D");
        //     //wapas aaunga, toh visited toh revert krna padefga
        //     //backtracking
        //     visited[newx][newy] = false;
        // }
        
        // //LEFT
        // //i,j -> i,j-1
        //  newx = curr_x;
        //  newy = curr_y-1;
        // if(isSafe(newx,newy,m,visited,n)) {
        //     visited[newx][newy] = true;
        //     solve(m,visited,n,ans,newx,newy,destx,desty,output+"L");
        //     //wapas aaunga, toh visited toh revert krna padefga
        //     //backtracking
        //     visited[newx][newy] = false;
        // }
        // //RIGHT
        // //i,j, i,j+1
        //  newx = curr_x;
        //  newy = curr_y+1;
        // if(isSafe(newx,newy,m,visited,n)) {
        //     visited[newx][newy] = true;
        //     solve(m,visited,n,ans,newx,newy,destx,desty,output+"R");
        //     //wapas aaunga, toh visited toh revert krna padefga
        //     //backtracking
        //     visited[newx][newy] = false;
        // }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<bool> > visited(n, vector<bool>(n,0));
        ///rat k row and column index k liye niche wale 2 variable le rha hu
        int curr_x = 0;
        int curr_y = 0;
        //MAIN YHA PR GALTI KRTA HU
        //start me RAT (0,0) pr hoga, that why visited true mark karo
        visited[0][0] = true;
        //destination k row and col index k liye 2 variable use krra hu
        int destx = n-1;
        int desty = n-1;
        //answer build up krne k liye string
        string output = "";
        
        //important case
        if(m[0][0] == 0) {
            return ans;
        }
        
        
        //function call
        solve(m,visited,n,ans,curr_x,curr_y,destx,desty,output);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends