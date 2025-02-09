#include<iostream>
using namespace std;
int main(){
    int no;
   while(true){ 
    cin>>no;
        if(no%13==0){
            continue;
        }
        if(no%7==0){
            break;
        }
        cout <<"No "<<no<<endl;

    }
    cout<<"Came out of loop!"<<endl;
    return 0;

}