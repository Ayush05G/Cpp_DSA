#include <bits/stdc++.h>
using namespace std;

// Iterative Solution
class Solution {
public:
    string removeOccurrences(string full, string pattern) {
        
        while(full.find(pattern) != string::npos) {
            full.erase(full.find(pattern), pattern.length());
        }
        return full;

    }
};

// Recursive Solution
class Solution {
public:
    void RemoveOccur(string&s,string&part){
        int found=s.find(part);
        if(found!=string::npos){
            string left=s.substr(0,found);
            string right=s.substr(found+part.length(),s.length());
            s=left+right;
            RemoveOccur(s,part);
        }
        else 
        return;
    }

    string removeOccurrences(string s, string part) {
        RemoveOccur(s,part);
        return s;
    }
};