#include <bits/stdc++.h>
using namespace std;

void merge_sort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid-1);
    merge_sort(arr, mid+1, end);
    //merge(arr, start, mid, end);
}

int power(int x, int n){
    if(n == 0) return 1;
    if(x == 0) return 0;
    int temp = power(x, n/2);
    if(n % 2==0){
        return temp*temp;
    } else{
        return temp*temp*x;
    }
}

int main() {
    int result=power(2, 3);
    cout << result << endl;
    
    return 0;
}