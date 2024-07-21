#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
    int left[mid - start + 1];
    int right[end - mid];
    for (int i = 0; i <= mid - start; i++) {
        left[i] = arr[start + i];
    }
    for (int j = 0; j < end - mid; j++) {
        right[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = start;
    while (i <= mid - start || j < end - mid) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i <= mid - start) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < end - mid) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid-1);
    merge_sort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int ceilSearch(int arr[], int low, int high, int x) {
	int mid;
	if (x < arr[low])
		return low;
	if (x >= arr[high])
		return -1;
	mid = (low + high) / 2;
	if (arr[mid] == x)
		return mid;
	else if (arr[mid] < x) {
		if (mid + 1 <= high && x <= arr[mid + 1])
			return mid + 1;
		else
			return ceilSearch(arr, mid + 1, high, x);
	}
	else {
		if (mid - 1 >= low && x > arr[mid - 1])
			return mid;
		else
			return ceilSearch(arr, low, mid - 1, x);
	}
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
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // int arr[] = {1, 2, 8, 10, 10, 12, 19};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int x = 5;
    // int index = ceilSearch(arr, 0, n-1, x);
    // if(index == -1){
    //     cout << "Ceil of " << x << " doesn't exist in the array" << endl;
    // } else{
    //     cout << "Ceil of " << x << " is " <<index<< endl;
    // }

    // int result=power(2, 3);
    // cout << result << endl;

    return 0;
}