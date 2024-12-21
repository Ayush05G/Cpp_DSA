class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<string, int> seqCount; // stores 10 sized window substring
        vector<string> ans;

        if (s.size() < 10)
            return {};

        // slide the 10 size window
        for (int i = 0; i <= s.size() - 10; i++)
        {
            string current10SizeWindowSubString = s.substr(i, 10);
            seqCount[current10SizeWindowSubString]++;
        }

        // for(auto it:seqCount){
        //     if(it.second > 1)
        //         ans.push_back(it.first);
        // }

        // seqCount : {string, int}
        for (auto &[subStr, freq] : seqCount)
        {
            if (freq > 1)
                ans.push_back(subStr);
        }
        return ans;
    }
};