class Solution
{
public:
    int beautySum(string s)
    {
        int beautySum = 0;
        // unordered_map<char, int>mp;

        // find all substrings
        for (int i = 0; i < s.size(); i++)
        {
            // mp.clear(); //
            int mp[256] = {0}; // only 26 char ki freq store kar raha hai
            for (int j = i; j < s.size(); j++)
            {
                // char ch = s[j];
                char &ch = s[j];
                mp[ch]++; // freq update of the char ch

                int mini = INT_MAX;
                int maxi = INT_MIN;

                // find most and least freqent ch from the map
                // for(auto each:mp){
                //     maxi = max(maxi, each.second);
                //     mini = min(mini, each.second);
                // }

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    if (mp[ch] > 0)
                    { // if char was present in the substring
                        maxi = max(maxi, mp[ch]);
                        mini = min(mini, mp[ch]);
                    }
                }

                int beauty = maxi - mini;
                beautySum += beauty;
            }
        }
        return beautySum;
    }
};