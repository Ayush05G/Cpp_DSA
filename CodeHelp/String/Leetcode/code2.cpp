class Solution {
public:
    string removeOccurrences(string full, string pattern) {
        

        //jab tak full string k andar pattern string 
        //milti rahegi, tab tak loop chalao
        
        while(full.find(pattern) != string::npos) {
            //full string me se erase karo
            //erase function k 2 argument hai
            //first arguement me, pattern ka starting index dena hai
            // full.find(pattern), hume starting index of pattern inside
            //full string provide krra hau
            //2nd argument, usme specify krna hai, k kitne character
            //remove karna chahte ho, starting index se
            full.erase(full.find(pattern), pattern.length());
        }
        return full;

    }
};