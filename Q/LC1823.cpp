#include<vector>
using namespace std;

class Solution {
public:
      int solve(vector < int >& v , int k , int index)
      {
        if( v.size() == 1) return v[0];
         index = (index+k)%v.size();
         v.erase( v.begin()+index);
        return  solve( v , k , index);
      }
    int findTheWinner(int n, int k) {
          vector < int > v;
          for( int i = 1; i <= n; i++)
          v.push_back(i);
          k--;
         return solve( v , k , 0);
        
    }
};