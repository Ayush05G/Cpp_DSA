class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int deficit = 0;
        int balance = 0;

        for(int i=0; i<gas.size(); i++) {
            if(balance + gas[i] < cost[i]) {
                //deficit case
                deficit += balance+gas[i]-cost[i];
                //deficit case -> aage nahi ja skta , start update
                start = i+1;
                //agar deficit exist krta h , toh common sense hai
                //k balance me koi bhi gas nhi hogi
                //that swhy balance gain zero kardo
                balance = 0;
            }
            else {
                //extra gas bach gyi h, balance me add krdo 
                balance = balance + gas[i]-cost[i];
            }
        }
        //deficit -> -ve value
        //balance -> +ve value
        //>= 0 -> 0 or extra gas bach jaegi overall -> circle complete

        if(balance + deficit >= 0) 
            return start;
        else
            return -1;
    }
};