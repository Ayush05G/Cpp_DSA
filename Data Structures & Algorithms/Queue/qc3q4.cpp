//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<char,int> freq;
		    string ans = "";
		    queue<char> q;
		    
		    for(int i=0; i<A.length(); i++) {
		        char ch = A[i];
		        //initial state maintain krne k liye
		        freq[ch]++;
		        q.push(ch);
		        //let's find the answer now 
		        while(!q.empty()) {
		            char frontElement = q.front();
		            //check whether frontElement is 
		            //answer or not
		            if(freq[frontElement] == 1) {
		                ans.push_back(frontElement);
		                break;
		            }
		            else {
		                //frontElement is duplicate element
		                q.pop();
		            }
		        }
		        ///IMportant condition
		        //agar sab duplicate lement the, toh q empty hogi
		        //agar koi bhi unique element h, toh q empty nahi hogi
		        if(q.empty()) {
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends