//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
        
    deque<long long int> q;
    vector<long long>  ans;
    //index store karenge hum queue k andar, kyoki, vo hume bata dega 
    //k current element current window me hai ya nahi 
    
    //step1: process first window
    for(int i=0; i<k; i++ ){
        int element = A[i];
        
        if(element < 0) {
            q.push_back(i);
        }
    }
    //store answer for first window
        if(q.empty()) {
            ans.push_back(0);
        }
        else {
            int index = q.front();
            int element = A[index];
            ans.push_back(element);
        }
    
    //above window stores the indexes of all the -ve numbers inside the first window
    //step2: process remaining windows -> ans/removal/addition
    for(int i=k; i<N; i++) {

        //step B -> removal of elemnts which are not inside current window
        if(!q.empty() && q.front() < i-k+1 ) {
            q.pop_front();
        }
        //step C -> addition of new element
        int element = A[i];
        if(element < 0) {
            q.push_back(i);
        }
                //stepA -> ans store karr rhe h purani window ka 
        if(q.empty()) {
            ans.push_back(0);
        }
        else {
            int index = q.front();
            int element = A[index];
            ans.push_back(element);
        }
    }
    
    return ans;
    
    
    
    
    
    
    
    
 }