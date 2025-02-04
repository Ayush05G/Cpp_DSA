class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = 0;
        int e = 0;
        int sum = 0;
        int len = INT_MAX;

        while(e < nums.size()) {
            sum = sum + nums[e];

            //ho skta h ye sum < ho , ya fer >= ho 
            while(sum >= target) {
                //minimise
                //sabse phle cheez, apke pass ek valid ans h toh store it 
                len = min(len, e-s+1);
                //minimise kia, sum decrease hoga jaha bhi start h  , uss number se
                sum = sum - nums[s];
                s++;
            }
            //iagar main yaha pohocha , iska mtlb kya h 
            //iska mtlb ye h k sum < target hogya 
            //jab sum < target hota h , tab kya krte h 
            //expand
            e++;
        }
        if(len == INT_MAX) {
            return 0;
        }
        else {
            return len;
        }
    }
};