//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool cmp(pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    }
    int maxMeetings(vector<int> start, vector<int> end) {
       
        vector<pair<int,int> > time;
        for(int i=0; i<start.size(); i++) {
            time.push_back({start[i], end[i]});
        }
        
        sort(time.begin(), time.end(), cmp);
        //sort basis on ending time 
        
        //main ye guranatee se keh skta hu k sabse pehli meeting toh mnain pkka include krunga 
        int count = 1;
        int prevStart = time[0].first;
        int prevEnd = time[0].second;
        
        for(int i=1; i<start.size(); i++) {
            int currStart = time[i].first;
            int currEnd = time[i].second;
            if(currStart > prevEnd) {
                //include kr skta hu 
                count++;
                //shifting 
                prevStart = currStart;
                prevEnd = currEnd;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends