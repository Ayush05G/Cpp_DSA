class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x>0 && x%10==0))
        {
            return false;
        }
        long long ans = 0;
        int temp=x;
        while(x>0)
        {
            int a =x%10;
            x /=10;
            ans =ans*10+a;
        }
            if(ans==temp)
            {
                return true;
            }
            else
            {
                return false;
            }
    }
};