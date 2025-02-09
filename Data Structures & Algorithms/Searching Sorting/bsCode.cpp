#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
    int main() {
        int arr[]={10,20,30,40,50,60,70,80,90,100};
        int n=10;
        int target=20;
        int s = 0;
        int e = n-1;
        int mid;

        while(s <= e) {
            int mid = s + (e-s)/2;
            if(arr[mid] == target) {
                cout<<mid;
                return 0;
            }
            if(target > arr[mid] ){
                //right me jao
                s= mid + 1;
            }
            else if(target < arr[mid] ) {
                //left me jao 
                e = mid - 1;
            }
            // //ye main bhul jata hu
            // mid = s + (e-s)/2;
        }
        //agar main yaha pohoch gya
        //iska mtlb elemnt nahi mial
        //noit found -> return -1;
        return 0;
    }