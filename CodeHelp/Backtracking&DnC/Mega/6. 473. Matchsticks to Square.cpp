class Solution
{
public:
    bool solve(vector<int> &matchsticks, vector<int> &sides, int i)
    {
        if (i == matchsticks.size()) // all matchsticks have been tried
        {
            return sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && sides[3] == 0;
            // if all sides become 0, means we have found 4 equal subsets
        }

        bool ans = false;
        // ith matchstick can be a part of A / B / C / D
        for (int j = 0; j < sides.size(); j++)
        {
            if (matchsticks[i] <= sides[j])
            {
                sides[j] -= matchsticks[i]; // include
                ans = ans || solve(matchsticks, sides, i + 1);
                if (ans == true)
                    return true;
                sides[j] += matchsticks[i]; // Backtrack
            }
        }
        return ans;
    }

    bool makesquare(vector<int> &matchsticks)
    {
        if (matchsticks.size() < 4)
            return false;

        auto sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0)
            return false;

        int sideSum = sum / 4;         // int
        vector<int> sides(4, sideSum); // 0 -> A side ka sum
                                       // 1 -> B side ka sum

        // sort in dsc order, to escape extra RE calls
        sort(matchsticks.rbegin(), matchsticks.rend());
        return solve(matchsticks, sides, 0);
    }
};