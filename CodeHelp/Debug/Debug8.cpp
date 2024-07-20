#include <bits/stdc++.h>
using namespace std;

void merge_sort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid-1);
    merge_sort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main() {
    return 0;
}