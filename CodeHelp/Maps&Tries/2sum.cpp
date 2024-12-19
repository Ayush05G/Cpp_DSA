class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int> > map;
        
        //value to indexes store
        for(int i=0; i<nums.size(); i++) {
            int val = nums[i];
            map[val].push_back(i);
        }   
        //ab aapne har value k hr possible index ki mapping store krli h

        for(int i=0; i<nums.size(); i++) {
            int current = nums[i];
            int required = target - nums[i];
            if(map.find(required) != map.end()) {
                //found
                //1 element ko 1 hi baar use krna h 
                //duplicate element wale case ko bhi handle krna h 

                //duplicate elemnt wala case
                if(required == current  && map[current].size() == 1) {
                    //iska mtlab main same element kop 2 baar use krra hu 
                    continue;
                }
                if(required == current && map[current].size() > 1) {
                    //duplicate case
                    return {map[current][0], map[current][1]};
                }
                else {
                    //required != current
                    return {i,map[required][0]};
                }
            }
        }
        return {-1,-1};
    }
};