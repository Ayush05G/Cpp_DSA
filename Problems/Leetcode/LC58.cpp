#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int l=s.size()-1;
        while(s[l]==' '){
            l--;
        }
        if(l==0) return 1;
        int j=l;
        while(j>=0 && s[j]!=' '){
            j--;
        }
        return l-j;
}
};