int sherlockAndAnagrams(string s)
{
    unordered_map<string, int> anagramatic_substring_count;
    int anagram_pairs = 0; // ans yahi find krna hai

    // Generate all substrings
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            string substring = s.substr(i, j - i + 1);
            // sort
            sort(substring.begin(), substring.end());
            // update count in map
            anagramatic_substring_count[substring]++;
        }
    }

    // Cal. pairs
    for (auto e : anagramatic_substring_count)
    {
        int count = e.second;
        // if(count > 1){
        // find unique pairs
        anagram_pairs += (count * (count - 1)) / 2;
        // }
    }
    return anagram_pairs;
}