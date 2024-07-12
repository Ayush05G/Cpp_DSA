#include<bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int n) {
        if(n<=1){
           return true;
        }
        if(n%4!=0){
           return false;
        }
       
        return isPowerOfFour(n/4);
    }

    double myPow(double x, int n) {

       int p = abs(n);
       double ans = 1.0;
       while(p>=1){
        p-- ;
          ans *= x;
       }
       return n<0 ? 1/ans : ans;    
    }

    int returnPermutations(string input, string output[]){
    int count = 0;
    string created;
    for(int i=0;input[i]!='\0' && input.length()>1;i++){
        char ch = input[i];
        int start = count;
        created = input.substr(0,i) + input.substr(i+1);
        count = count + returnPermutations(created,output+count);
        for(int k=start;k<count;k++){
            output[k] = ch + output[k];
        }
    }
    if(input.length()==1){
        for(int k=0;input[k] !='\0';k++){
            output[count] = output[count] + input[k];
            count++;
        }
    }
    
    return count;
}

    void removeConsecutiveDuplicates(char *input) {
	if(input[0] == '\0'){
        return;
    }
	if(input[0] == input[1]){
        int i = 2;
        for(;input[i]!='\0';i++){
            input[i-1] = input[i]; 
        }
        input[i-1] = input[i];
        removeConsecutiveDuplicates(input);
    }
    else
    removeConsecutiveDuplicates(input+1);
}

void shift(char input[]){
    int i =1;
    for(i=1;input[i]!='\0';i++)
        input[i-1] = input[i];
    input[i-1] = '\0';
}
void removeX(char input[]) {
    if(input[0]=='\0'){
        return;
    }
    if(input[0]=='x'){
        shift(input);
    	removeX(input);
    }
    else
    removeX(input+1);
}

int main(){
    // int n;
    // cin>>n;
    // cout<<isPowerOfFour(n);

    // double x;
    // int n;
    // cin>>x>>n;
    // cout<<myPow(x,n);

    string input;
    cin>>input;
    string output[1000];
    int count = returnPermutations(input,output);
    for(int i=0;i<count;i++){
        cout<<output[i]<<endl;
    }

    // char input[100];
    // cin.getline(input, 100);
    // // removeConsecutiveDuplicates(input);
    // removeX(input);
    // cout << input << endl;

    return 0;
}