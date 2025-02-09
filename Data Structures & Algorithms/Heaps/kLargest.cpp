class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        //max-heap
        priority_queue<int> pq;

        for(int i=0; i<nums.size(); i++) {
            int val = nums[i];
            pq.push(val);
        }
        int ans = -1;
        while(k != 0) {
            ans = pq.top();
            pq.pop();
            k--;
        }
        return ans;



        
        // //min heap
        // priority_queue<int,vector<int>, greater<int> > pq;

        // //intial state maintain -> insert first k elements
        // for(int i=0; i<k; i++) {
        //     pq.push(nums[i]);
        // }
        // //process remaining elements ko, 
        // //hum chjahte h, k end me heap me 
        // //k large element ho, taaki top me kth largest mil jaye 
        // //k large elemnent rakhne k liye, we will make sure
        // //k hum bs large elemnet hi insert kare
        // for(int i=k; i<nums.size(); i++) {
        //     int element = nums[i];
        //     if(element > pq.top()) {
        //         pq.pop();
        //         pq.push(element);
        //     }
        // }
        // int ans = pq.top();
        // return ans;
    }
};