#include<iostream>
using namespace std;
int main(){
    int n;
    int i;
    cin>>n;
    for(i=2;i<=n-1;i++){
        if(n%i==0){
            cout<<"Not Prime"<<endl;
            break;

        }
     }
      if(i==n){
        cout<<n<<" is Prime"<<endl;

     }
    return 0;
}
