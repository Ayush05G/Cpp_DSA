//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    //first we will create mask
		    //and then us e mask to create subsequence 
		    int len = s.length();
		    int n = (1 << len );
		    
		    vector<string> ans;
		    
		    for(int num=0; num < n; num++) {
		        //for each mask , just find the subseqence basis on the bits
		        string temp = "";
		        //now, will go to each index and check whethere
		        //i should incliude or exclude the character 
		        for(int i=0; i<len; i++) {
		            char ch = s[i];
		            int mask = (1<< i);
		            if(num & mask) {
		                //can include the character
		                temp.push_back(ch);
		            }
		        }
		        if(temp.length() > 0)
		            ans.push_back(temp);
		    } 
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends