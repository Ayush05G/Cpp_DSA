#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n%2==0 and n%3==0){
        cout<<n<<" is divisible by 2 and 3"<<endl;
        cout<<"if block"<<endl;
    }
    else if(n%2==0){
        cout<<n<<" is divisible by 2"<<endl;
        cout<<"Else if 1 block"<<endl;
    }
    else if(n%3==0){
        cout<<n<<" is divisible by 3"<<endl;
        cout<<"Else if 2 block"<<endl;
    }
    else{cout<<n<<" is not divisible by 2 and 3"<<endl;
    cout<<"Else block"<<endl;}

 return 0;
}