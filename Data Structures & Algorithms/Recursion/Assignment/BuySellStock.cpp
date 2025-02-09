#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void profit(vector<int>& prices,int i,int&minprice,int&maxProfit){
        if(i==prices.size())
        return;
        if(prices[i]<minprice)
        minprice=prices[i];
        int todayprofit=prices[i]-minprice;
        if(todayprofit>maxProfit) maxProfit=todayprofit;
        profit(prices,i+1,minprice,maxProfit);    
    }

    int maxProfit(vector<int>& prices) {
        int minprice=INT_MAX;
        int maxProfit=0;
        profit(prices,0,minprice,maxProfit);
        return maxProfit;
        
    }
};