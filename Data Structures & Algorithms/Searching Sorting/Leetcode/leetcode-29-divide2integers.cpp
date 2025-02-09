class Solution
{
public:
    int divide(int dividendx, int divisorx)
    {
        if (dividendx == INT_MIN && divisorx == -1)
            return INT_MAX;

        bool ans_pos_sign = true; // kya final ans pos hai?
        if (dividendx < 0 && divisorx > 0)
            ans_pos_sign = false;
        if (dividendx > 0 && divisorx < 0)
            ans_pos_sign = false;

        // now i can divide with BS using only pos number;
        long long int dividend = abs(dividendx);
        long long int divisor = abs(divisorx);
        long long int s = 0, e = dividend;
        long long ans = 0;

        while (s <= e)
        {
            long long mid = ((e - s) >> 1) + s;

            // check kya mid ans hai?
            if (mid * divisor <= dividend)
            {

                ans = mid;
                s = mid + 1;
            }
            else
                e = mid - 1;
        }

        if (ans_pos_sign == false)
            return -ans;
        return ans;
    }
};