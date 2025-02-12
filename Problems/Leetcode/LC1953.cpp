class Solution {
    public:
        long long numberOfWeeks(vector<int>& milestones) {
            sort(milestones.rbegin(),milestones.rend());
            long long max=milestones[0];
            milestones[0]=0;
            long long sum=accumulate(milestones.begin(),milestones.end(),0LL);
            long long diff=max-sum;
            long long total=max+sum;
            if(diff<=1)
            return total;
            else
            return total-diff+1;
        }
    };