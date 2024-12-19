class Solution {
public:
    //track individual word ka count
    unordered_map<string,int> map;
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        for(int i=0; i<words.size(); i++) {
            map[words[i]]++;
        }

        int wordLength = words[0].length();

        //offset logic -> start -> 0,1,2,    < wrdLength
        for(int offset=0; offset < wordLength; offset++) {
        
            unordered_map<string,int> visited;
            //ans mila kya check krne k liye we, need track count
            int count = 0;

            //ab main wordLength k substring uthaunga and check karunga 
            for(int i=offset; i + wordLength<=s.length(); i = i+wordLength ) {
                string substr = s.substr(i, wordLength);
                //check whtther substr is valid or not 
                
                if(map.find(substr) == map.end()) {
                    //invalid string
                    ///purane saare answer ko bhulna chahiye and 
                    //naye start krna chahiye 
                    visited.clear();
                    count = 0;
                }
                else {
                    //valid string
                    visited[substr]++;
                    count++;

                    //GAME CHANGER - removal 
                    while(visited[substr] > map[substr]) {

                        //hr word removal pr visited and count done me se
                        //vo word hatega
                        string temp = s.substr(i-(count-1)*wordLength, wordLength);
                        visited[temp]--;
                        count--;
                    }
                    //GAME CHANGER

                    //ans mila kya 
                    if(count == words.size()) {
                        //ans milgya 
                        //mujhe starting index return ans me insert krna h 
                        ans.push_back(i-(count-1)*wordLength);
                    }

                }
            }


        }
        return ans;
    }
};