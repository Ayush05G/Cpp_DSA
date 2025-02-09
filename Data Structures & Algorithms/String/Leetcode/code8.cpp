class Solution {
public:

    void normalise(string &str) {
        char start = 'a';
        unordered_map<char,char> mapping;

        for(int i=0; i<str.length(); i++) {
            char stringKaCharacter = str[i];
            if(mapping.find(stringKaCharacter) == mapping.end()) {
                //if mapping pehle se present nahi h 
                //then create it and move ahead
                mapping[stringKaCharacter] = start;
                start++;
            }
        }

        //mapping create ho chuki h 
        //string str ko update normalise kardo using mapping 
        for(int i=0; i<str.length(); i++) {
            char mappedCharacter = mapping[str[i]];
            str[i] = mappedCharacter;
        }
        //toh humne str wali string ko normalise / update krdia 
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans ;

        //step A: pattern normalise 
        normalise(pattern);
        ///stepB: words ki list me hr ek word ko normlaise 
        // karna hai, and compare krna h pattern se
        //if pattern k equal aagya, toh ans me store krna h 
        for(int i=0; i<words.size(); i++) {
            //ith string 
            string currWord = words[i];
            normalise(currWord);
            if(currWord == pattern) {
                ans.push_back(words[i]);
            }
        }

        return ans;





    }
};