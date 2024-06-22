class Solution
{
public:
    bool canKokoFinishBananasWithKSpeed(vector<int> &piles, int h, int k)
    {
        long long int totalHoursTakenByKokoToFinishAllBananas = 0;
        for (int i = 0; i < piles.size(); i++)
            totalHoursTakenByKokoToFinishAllBananas += ceil(piles[i] / (double)k);

        // if(totalHoursTakenByKokoToFinishAllBananas <= h) return true;
        // return false;
        return totalHoursTakenByKokoToFinishAllBananas <= h;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int start = 1;
        // auto it = max_element(piles.begin(), piles.end());
        // int end = *it;
        int end = *max_element(piles.begin(), piles.end());
        // end to mere pkka ans hai,
        int ans = 0;

        // TC: O(Log(Max(Piles)) * O(n)) -> O(n*log(max(piles)))
        while (start <= end)
        {
            int mid = (start + end) >> 1;
            int k = mid;
            if (canKokoFinishBananasWithKSpeed(piles, h, k))
            {
                // koko will finish all bananas
                // without being caught
                ans = k;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
};