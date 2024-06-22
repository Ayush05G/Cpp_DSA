class Solution {
public:
//this function returns the count of palindromic substrings
//using i and j as center and exapanding around it in every iteration, if possible.
    int expandAroundCenter(string s, int i, int j) {
        int count = 0;
        while(i >= 0 && j <s.length() && s[i] == s[j]) {
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int totalCount = 0;
        for(int center=0; center<s.length(); center++) {
            //odd
            int i = center;
            int j = center;
            int oddPalSubStringKaCount = expandAroundCenter(s,i,j);
            //even
            i = center;
            j = center+1;
            int evenPalSubStringKaCount = expandAroundCenter(s,i,j);
            totalCount = totalCount + oddPalSubStringKaCount + evenPalSubStringKaCount;
        }
        return totalCount;
    }
};