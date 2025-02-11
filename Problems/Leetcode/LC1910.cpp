class Solution {
    public:
        string removeOccurrences(string s, string part) {
            int found=s.find(part);
            if(found!=string::npos){
                string left=s.substr(0,found);
                string right=s.substr(found+part.length(),s.length());
                s=left+right;
                return removeOccurrences(s,part);
            }
            else 
            return s;
        }
    };