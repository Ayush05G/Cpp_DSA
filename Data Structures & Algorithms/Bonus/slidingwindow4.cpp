class Solution {
public:
    string minWindow(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();

        if(len1 < len2) {
            //no answer
            return "";
        }

        //inn do variables k basis opr main exact string find out kr skta hu , substr use krke
        int ansIndex = -1;
        int ansLen = INT_MAX;

        //below 2 maps reflect the current windows of the string s
        unordered_map<char,int> sMap;
        unordered_map<char, int> tMap;

        //values fill krte h tMap k andar 
        for(auto i: t) {
            tMap[i]++;
        }

        int start = 0;
        int end = 0;
        //count tracks total matched characters inn the window
        int count = 0;

        //variable-size window wlaa logic run krre h 
        while(end < s.length()) {
            char ch = s[end];
            //udpate krna h sMap me, kyoki sMap  "s" wali string 
            //ki window me kon kon se characters h unko track krne k liye banaya h 
            sMap[ch]++;
            //possibility h ye character t k andar ho ya fer na ho
            //agar ye character t wali string me bhi h , 
            //toh isko matched characters k andar count krna padega 
            if(sMap[ch] <= tMap[ch]) {
                count++;
            }

            //ab ye bhi ho skta h k count i.e. total number of matched characters exactly
            // len2 i.e. length of string t kequal aajaye 
            //iska mtlb ek aisi window milgyi h jisme t k saare character presnet h 
            if(count == len2) {
                //mujhe 1 aise window milgyi h, jisme answer present  h
                //minimise

                while(sMap[s[start]] > tMap[s[start]]) {
                    sMap[s[start]]--;
                    start++;
                }
                //ans store 
                int windowKiLength = end - start + 1;
                if(windowKiLength < ansLen) {
                    ansLen = windowKiLength;
                    ansIndex = start;
                }
            }
            //ab line 60 pr kab aaoge ?
            //jab ek valid ans nhi milta, tab hum expand krte h 
            end++;
        }
        if(ansIndex == -1) {
            return "";
        }
        else {
            return s.substr(ansIndex, ansLen);
        }
    }
};