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

    int subset(int input[], int n, int output[][50], int k) {
    if(n==0){
        output[0][0] = 0;
        return 1;
    }
    
    int small = subset(input+1,n-1,output,k);
    int count = 0;
    
    for(int i=0;i<small;i++){
        output[small+count][1] = input[0];
        int sum = input[0];
        int l = 0;
        for(int j=2;output[small-count-1][j-1]!=0;j++){
            l++;
            output[small+count][j] = output[small-count-1][j-1];
            sum = sum + output[small-count-1][j-1];
        }
        output[small+count][0] = -1;
        if(sum==k){
            output[small+count][0] = l+1;
        }
        count++;
    }
    return small+count;
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    int temp[1110000][50];
    int size = subset(input,n,temp,k);
    int m=0;
    for(int i=0;i<size;i++){
        if(temp[i][0]>0){
            for(int j=0;j<=temp[i][0];j++){
                output[m][j] = temp[i][j];
            }
            m++;
        }
    }
    
    return m;
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

    int input[20],length, output[1000][50], k;
    cin >> length;
    for(int i=0; i < length; i++)
        cin >> input[i];
    cin >> k;
    int size = subsetSumToK(input, length, output, k);
    for( int i = 0; i < size; i++) {
        for( int j = 1; j <= output[i][0]; j++) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    // string input;
    // cin>>input;
    // string output[1000];
    // int count = returnPermutations(input,output);
    // for(int i=0;i<count;i++){
    //     cout<<output[i]<<endl;
    // }

    // char input[100];
    // cin.getline(input, 100);
    // // removeConsecutiveDuplicates(input);
    // removeX(input);
    // cout << input << endl;

    return 0;
}