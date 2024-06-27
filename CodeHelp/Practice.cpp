#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<limits.h>
using namespace std;

/* //Good one to revise
    void palindromepyramid(int n){
    int k=n;
    for(int row=0;row<n;row++){
        int c=1;
        for(int j=0;j<k;j++){
           if(j<n-row-1) 
        cout<<" ";
        else if (j<=n-1){
        cout<<c;
        c++;}
        else if(j==n){
            c=c-2;
            cout<<c;
            
         }
        else{c--;
            cout<<c;
            
        }
    }
        k++;
        cout<<endl;
    }  
  } */

// LC 14 Good question to revise
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int i=0;
        while(true){
            char curr_ch=0;
            for(auto str:strs){
                if(i>=str.size()){
                    curr_ch=0;
                    break;
                }
                if(curr_ch==0){
                    curr_ch=str[i];

                }
                else if(str[i]!=curr_ch){
                    curr_ch=0;
                    break;
                }
            }
            if(curr_ch==0)
            break;
        
        ans.push_back(curr_ch);
        i++;
    }
    return ans;
    }
};

    int main(){
        /*int n;
        cin>>n;
        palindromepyramid(n);*/
        int N;
        cin>>N;
        for(int i=0;i<2*N-1;i++){
            int cond;
            if (i<N){
                cond=i;}
                else{
                    cond=N-(i%N)-2;
                }
            
            for(int j=0;j<=cond;j++){
                cout<<"*";
            }
            cout<<endl;

    }
     return 0;    
    }