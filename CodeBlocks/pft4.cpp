#include<iostream>
using namespace std;
int main(){
    char ch;
    ch=cin.get();
    while(ch!='.'){
        cout<<ch;
        ch=cin.get();
    }
    return 0;
}