#include<iostream>
using namespace std;

//Question 7(Doubt)
int main(){
    int no;
    cin>>no;
    int i=1;
    int n = 2*no-1;
    while(i<=(no)){
        int gaps = n-2*i+1,k=1;
        int j = i;
        while(k<=gaps/2){
            cout<<" ";
            k = k + 1;
        }
        int ch = n - gaps, z = (ch+1)/2;
        while(z>=1){
            cout<<j;
            j = j + 1;
            z = z - 1;
        }
        j = j - 1;
        z = (ch-1)/2;
        while(z>=1){
            j = j - 1;
            cout<<j;
            z = z - 1;
        }
        k = 1;
        while(k<=gaps/2){
            cout<<" ";
            k = k + 1;
        }
        cout<<"\n";
        i = i + 1;
    }
}

//Question 8(Doubt)
/*void printPatt(int n){
    int i=1;
    while(i<=n){
        int gaps = n-2*i+1,k=1;
        if(i>(n+1)/2){
            int no = (n+1)/2;
            gaps = 2*(i%no);
        }
        while(k<=gaps/2){
            cout<<" ";
            k = k + 1;
        }
        int ch = n - gaps;
        while(ch>=1){
            cout<<"*";
            ch = ch - 1;
        }
        k = 1;
        while(k<=gaps/2){
            cout<<" ";
            k = k + 1;
        }
        cout<<"\n";
        i = i + 1;
    }
    
}
int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    printPatt(n);
    return 0;
}*/