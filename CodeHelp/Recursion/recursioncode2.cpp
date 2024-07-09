#include <iostream>
using namespace std;

void printDigits(int n) {
    //base case
    if( n == 0) {
        return ;
    }

    //baaki recursion krdega 
    int newNumber = n / 10;
    printDigits(newNumber);

    //1 case main solve krdeta hu
    int digit  = n % 10;
    cout << digit << " ";
}

// int binarySearchRecursive(int arr[], int n, int s, int e, int target)
// {
//     // base case
//     if (s > e)
//     {
//         return -1;
//     }
//     int mid = (s + e) / 2;
//     if (arr[mid] == target)
//     {
//         return mid;
//     }
//     if (target > arr[mid])
//         return binarySearchRecursive(arr, n, mid + 1, e, target);
//     else
//         return binarySearchRecursive(arr, n, s, mid - 1, target);
// }

int binarySearchRecursive(int arr[], int n, int s, int e, int target)
{
    // base case
    if (s > e)
    {
        return -1;
    }

    int mid = (s + e) / 2;

    // 1 case main
    if (arr[mid] == target)
    {
        return mid;
    }
    // baakki recursion sambhal lega
    // arr[mid] agar target k equal nahi h
    //  iska matlab ya toh target bada h,
    // ya toh target chotta h
    if (target > arr[mid])
    {
        // right
        return binarySearchRecursive(arr, n, mid + 1, e, target);
    }
    else
    {
        // left
        return binarySearchRecursive(arr, n, s, mid - 1, target);
    }
}

// iterative - loop
int binarySearch(int arr[], int size, int target)
{
    int s = 0;
    int e = size - 1;
    int mid = (s + e) / 2;

    while (s <= e)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        if (target > arr[mid])
        {
            // right
            s = mid + 1;
        }
        else
        {
            // left
            e = mid - 1;
        }
        mid = (s + e) / 2;
    }
    return -1;
}

int main()
{   
    int n = 21478;
    printDigits(n);

    // int arr[] = {10, 20, 30, 40, 50, 60, 70};
    // int size = 7;

    // int target = 60;
    // int s = 0;
    // int e = size - 1;
    // int ans = binarySearchRecursive(arr, size, s, e, target);
    // cout << "answer index: " << ans << endl;

    return 0;
}