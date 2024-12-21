#include <bits/stdc++.h>
using namespace std;

/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/

class Node{
    public:
    
    bool isEnd = false;
    vector<Node*> children;
    char ch;
    
    Node(char ch){
        children.resize(26, NULL);
        this -> ch = ch;
    }
};

Node* root = new Node('#');

void insert(string word) {
    Node* rootCopy = root;
    for(int i = 0 ; i < word.size() ; i++){
        if(rootCopy -> children[word[i] - 'a'] == NULL){
            Node* toAdd = new Node(word[i] - 'a');
            rootCopy -> children[word[i] - 'a'] = toAdd;
            rootCopy = rootCopy -> children[word[i] - 'a'];
        }else{
            rootCopy = rootCopy -> children[word[i] - 'a'];
        }
    }
    rootCopy -> isEnd = true;
    
}

bool search(string word) {
    Node* rootCopy = root;
    for(int i = 0 ; i < word.size() ; i++){
        if(rootCopy -> children[word[i] - 'a'] == NULL){
            return false;
        }else{
            rootCopy = rootCopy->children[word[i] - 'a'];
        }
    }
    if(rootCopy->isEnd)return true;
    return false;
}

bool startsWith(string prefix) {
    Node* rootCopy = root;
    for(int i = 0 ; i < prefix.size() ; i++){
        if(rootCopy -> children[prefix[i] - 'a'] == NULL){
            return false;
        }else{
            rootCopy = rootCopy->children[prefix[i] - 'a'];
        }
    }
    return true;
}

unordered_map<string, bool> dp;
bool solve(string str, Node* trie){
    if(str.size() == 0){
        return true;
    }
    if(dp.find(str) != dp.end())return dp[str];
    
    for(int i = 0 ; i < str.size() ; i++){
        string prefix = str.substr(0, i + 1);
        string suffix = str.substr(i + 1);
        
        if(search(prefix)){
            if(solve(suffix, trie))
            return dp[str] = true;
        }
    }
    
    return dp[str] = false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    for(auto word : wordDict)insert(word);        
    return solve(s, root);
}

int main(){
    vector<string> wordDict = {"leet", "code"};
    string s = "leetcode";
    cout << wordBreak(s, wordDict);
    return 0;
}