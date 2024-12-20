class TrieNode{
    public: 
        char data;
        unordered_map<char, TrieNode*> children;
        bool isTerminal;

        TrieNode(char val ) {
            data = val;
            isTerminal = false;
        }
};

void insertWord(TrieNode* root, string word) {
            //base case 
            if(word.length() == 0) {
                root->isTerminal = true;
                return;
            }

            //1 case hum khud solve krenbge 
            char ch = word[0];
            TrieNode* child ;
            if(root->children.find(ch) != root->children.end()) {
                //present
                child = root->children[ch];
            }
            else {
                //absent
                child = new TrieNode(ch);
                root->children[ch] = child;
            }
            //baaki recursion
            insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word) {
    //base case
    if(word.length() == 0) {
        return root->isTerminal;
    }

    //1 case solve krdeta hu 
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()) {
        //present
        child = root->children[ch];
    }
    else {
        //absent
        return false;
    }
    //baaki recursion dekhlega
    bool recKaAns = searchWord(child, word.substr(1));
    return recKaAns;
}

bool searchPrefix(TrieNode* root, string word) {
    //base case
    if(word.length() == 0) {
        return true;
    }

    //1 case solve krdeta hu 
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()) {
        //present
        child = root->children[ch];
    }
    else {
        //absent
        return false;
    }
    //baaki recursion dekhlega
    bool recKaAns = searchPrefix(child, word.substr(1));
    return recKaAns;
}


class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('-');
    }

    void insert(string word) {
       insertWord(root, word);
    }
    
    bool search(string word) {
        bool ans = searchWord(root, word);
        return ans;
    }
    
    bool startsWith(string prefix) {
        bool ans = searchPrefix(root, prefix);
        return ans;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */