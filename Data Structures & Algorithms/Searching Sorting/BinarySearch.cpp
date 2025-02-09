#include <iostream>
#include <vector>
using namespace std;

// Given a sorted array arr[] of size N, some elements of array are moved to either of the adjacent positions, i.e., arr[i] may be present at arr[i+1] or arr[i-1] i.e. arr[i] can only be swapped with either arr[i+1] or arr[i-1]. The task is to search for an element in this array.

// Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 40
// Output: 2
// Explanation: Output is index of 40 in given array i.e. 2

// Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 90
// Output: -1
// Explanation: -1 is returned to indicate the element is not present

int applyBinarySearch(int arr[], int size, int target)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        // cout << "printing mid:  " << mid << endl;
        // cout << "target " << target << endl;
        // cout << "arr[mid]: " << arr[mid] << endl << endl;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid - 1] == target)
        {
            return mid - 1;
        }
        if (arr[mid + 1] == target)
        {
            return mid + 1;
        }

        if (target > arr[mid])
        {
            // right
            s = mid + 2;
        }
        else
        {
            // left
            e = mid - 2;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{

    int arr[] = {10, 3, 40, 20, 50, 80, 70};
    int size = 7;

    int target = 20;

    int ans = applyBinarySearch(arr, size, target);
    cout << "Found at Index: " << ans << endl;
    // if(ans == true) {
    //     cout << "target found" << endl;
    // }
    // else {
    //     cout << "target not found" << endl;
    // }

    return 0;
}