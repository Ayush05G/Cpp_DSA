class Solution {
public:
    void createMapping(unordered_map<char,char> &mapping, string key) {
        char start = 'a';

        for(int i=0; i<key.length(); i++) {
            //if mapping is not already present , then create it 

            if(mapping.find(key[i]) == mapping.end()) {
                mapping[key[i]] = start;
                start++;
            }
        }

    }

    string useMapping(unordered_map<char,char> &mapping, string message) {
        string ans = "";
        for(int i=0; i<message.length(); i++) {
            char mappedCharacter = mapping[message[i]];
            ans.push_back(mappedCharacter);
        }
        return ans;
    }
    string decodeMessage(string key, string message) {
        //step1: create mapping
        unordered_map<char,char> mapping;
        char spaceCharacter = ' ';
        mapping[spaceCharacter] = spaceCharacter;

        createMapping(mapping, key);

        //step2: use mapping and decode msg
        string ans = useMapping(mapping, message);
        return ans;
    }
};