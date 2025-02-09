//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& values, vector<int>& weights, int w) {
        vector<double> valWtRatio;
        
        for(int i=0; i<values.size(); i++ ) {
            double ratio = (values[i] * 1.0 / weights[i]);
            valWtRatio.push_back(ratio);
        }
        
        //to find the max ratio wala item, let's create a max heap 
        priority_queue< pair<double, pair<int,int>  > > pq;
        
        for(int i=0; i<values.size(); i++) {
            pq.push({valWtRatio[i], {values[i], weights[i]}});
        }
        
        //let's find the total value 
        double totalVal = 0;
        
        int capacity = w;
        
        while(capacity != 0 && !pq.empty()) {
            auto front = pq.top();
            pq.pop();
            
            double ratio = front.first;
            int value = front.second.first;
            int weight = front.second.second;
            
            //choose whole item include karu ya fer fraction me include karu
            if(capacity >= weight) {
                //whole item include karlo
                totalVal += value;
                capacity -= weight;
            }
            else {
                //fraction include karlo
                double valToInclude = ratio * capacity;
                totalVal += valToInclude;
                capacity = 0;
                break;
            }
        }
        return totalVal;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
    }
    return 0;
}

// } Driver Code Ends