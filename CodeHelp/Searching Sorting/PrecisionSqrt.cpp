#include <iostream>
#include <algorithm>
using namespace std;

int mySqrt(int n)
{
    int s = 0, e = n;
    int ans = 0;
    while (s <= e)
    {
        int mid = (s + e) >> 1;
        if (mid * mid <= n)
        {
            ans = mid;
            s = mid + 1; // go right
        }
        else
            e = mid - 1; //  left jata hu
    }
    return ans;
}

double myPrecisionSqrt(int n)
{
    double sqrt = mySqrt(n); // -> O(logn)

    /* O(precision) */
    int precision = 9;
    double step = 0.1;
    while (precision--)
    {
        double j = sqrt; // j->7.0;
        while (j * j <= n)
        {
            // store and compute
            sqrt = j;
            j += step; // j-> 7.1
        }
        // after this while loop i got 1 precision ans.
        step /= 10;
    }
    return sqrt;
}

double BSPrecision(int n)
{
    double start = 0;
    double end = n;
    double ans = 0;
    while ((end - start) > 0.000000001)
    {
        double mid = (start + end) / 2;
        double sqr = mid * mid;
        if (sqr <= n)
        {
            ans = mid;
            start = mid + 0.000000000000000000000000001;
        }
        else
            end = mid - 0.000000000000000000000000001;
    }
    return ans;
}

int main()
{
    int n = 63;
    double ans = myPrecisionSqrt(n); // TC: O(logn) + O(Precision).
    printf("M1: Precision Sqrt: %.9f\n", ans);
    // cout << ans << endl;
    // cout hota hai, it only print 5 precision.

    // zada kes kre?

    ans = BSPrecision(n);
    printf("M2: Precision Sqrt: %.9f\n", ans);
    return 0;
}