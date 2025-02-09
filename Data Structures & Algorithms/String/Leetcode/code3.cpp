class Solution {
public:
    bool checkPalindrome(string str, int s, int e) {
        while(s <= e) {
            if(str[s] != str[e]) {
                return false;
            }
            else {
                s++;
                e--;
            }
        }
        //valid palindrome
        return true;
    }
    bool validPalindrome(string s) {
        int len = s.length();
        int i=0; 
        int j = len-1;

        while(i <= j) {
            //same 
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            //different
            else {
                //s[i] != s[j]
                //iss case me character delete krke dekho
                //2 options
                //delete ith index wala character
                bool ansOne = checkPalindrome(s, i+1, j);
                if(ansOne == true)
                    return true;
                //delete jth index wala character
                bool ansTwo = checkPalindrome(s,i,j-1);
                bool finalAns = ansOne || ansTwo;
                return finalAns;
            }
        }
        //valid palindome, without any deletion
        return true;
    }
};