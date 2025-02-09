#include<iostream>
using namespace std;
int x = 100;
int main(){
 int x=10;
 cout<<x<<endl;
 for(int x=0;x<=5;x++){
    cout<<"Loop Scope "<<x<<endl;
 }
 cout<<" Local X "<<x<<endl;
 cout<<" Global X "<<::x<<endl;
    return 0;
}