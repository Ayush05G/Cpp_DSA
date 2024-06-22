#include<iostream>
#include<algorithm>
#include<limits.h>
#include<vector>
using namespace std;
/*void sortZeroOneTwo(int arr[], int size) {
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount=0;
    //counting
    for(int i=0; i<size; i++) {
        if(arr[i] == 0) {
            zeroCount++;
        }
        if(arr[i] == 1) {
            oneCount++;
            }
    if(arr[i] == 2) {
            twoCount++;}
    }
    //insertion
    fill(arr, arr+zeroCount, 0);
    fill(arr+zeroCount, arr+zeroCount+oneCount, 1);
    fill(arr+zeroCount+oneCount, arr+size, 2);
    return;
}*/
void printAllPairs(int arr[], int n) {
    for(int i=0; i<n; i++) {
        //for every i, we are running looping variable "j" from start to end
        for(int j=i+1; j<n; j++){
            cout << arr[i] <<"," << arr[j]<<"  ";
        }
        cout<<endl;
    }
}
int main(){
    //int arr[] = {2,0,1,2,1,2,0,2,1};
     //int size=9;
     int arr[] = {10,20,30,40,50,60};
     int size=6;
     //sortZeroOneTwo(arr,size);
    // cout << "Sorted array: ";

    printAllPairs(arr,size);
     
     return 0;    
    }