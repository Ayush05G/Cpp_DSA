#include<iostream>
#include<limits.h>
using namespace std;

void print(int arr[], int size) {
    for(int index=0; index<size; index++) {
        cout << arr[index] <<  " ";
    }
}

void solve1(int arr[], int n) {
    for(int i=0; i<n; i++) {
        arr[i] = arr[i] * 10;
    }
}

bool findTarget(int arr[], int size, int target) {

    for(int i=size-1; i>=0; i--) {
        if(arr[i] == target) {
            return true;
        }
    }
    return false;




    //traverse the entire array
    // for(int i=0; i<size; i++) {

    //     if( arr[i] == target) {
    //         //found
    //         return true;
    //     }
    // }
    // ///agar aap yaha tk pohoch gye toh
    // //iska mtlb poora loop chal chuka hai
    // //iska matlab poore loop me kahin bhi target nahi mila 
    // //iska mtlb element not found
    // //iskat matlab return false;
    // return false;
}

int findMax(int arr[], int size) {
    int maxAns = INT_MIN;
    for(int i=0; i<size; i++) {
        maxAns = max(maxAns, arr[i]);
    }
    return maxAns;
}

void printZeroesAndOnes(int arr[], int n) {
    int zeroCount = 0;
    int oneCount = 0;

    //traverse Array
    for(int i=0; i<n; i++) {
        int currElement = arr[i];
        
        if(currElement == 0) {
            zeroCount++;
        }
        if(currElement == 1) {
            oneCount++;
        }
    }
    cout << "Total Zeroes: " << zeroCount << endl;
    cout << "Total Ones: " << oneCount << endl;
}

void extremePrint(int arr[], int n) {
    int i = 0;
    int j = n-1;

    while(i <= j) {
        if(i == j) {
            cout << arr[i] << " ";
            break;
        }
        else {
            cout << arr[i] << " ";
            i++;
            cout << arr[j] << " ";
            j--;
        }

    }
}

int main() {

    int arr[] = {10,20,30,40,50,60,70};
    int size = 7;
    extremePrint(arr,size);

    // int arr[] = {10,20,30,40,50};
    // int size = 5;'
    // int arr[100];
    // int size;
    // cout << "Enter the number of elements" << endl;
    // cin >> size;

    // for(int i=0; i< size; i++) {
    //     cout << "Enter the input value for index: " << i << endl;
    //     cin >> arr[i];
    // }

    // printZeroesAndOnes(arr,size);

    // cout << "max number is: " << findMax(arr,size) << endl;

    // int target;
    // cout << "Enter the value of target" << endl;
    // cin >> target;

    // bool ans = findTarget(arr,size, target);
    // cout << "ans: " << ans << endl;
    // solve1(arr, size);
    // print(arr,size);


    
    // int arr[10];
    // //error
    // //int brr[]

    // int crr[] = {10,20,40,70};
    // int drr[4] = {0};

    // //cout << drr[0] << endl;
    // cout << crr[4] << endl;

    // int arr[4];
    // fill(arr,arr+4,101);
    // cout << arr[0] << " " << arr[1] << " " << arr[2] <<" " << arr[3] << endl;

    //input
    // int arr[5];
    // for(int index=0; index<5; index++) {
    //     cout << "Enter the value for box index: " << index << endl;
    //     cin >> arr[index];
    // }
    // //print
    // for(int index=0; index<5; index++) {
    //     cout << index[arr] << " ";
    // }


    return 0;
}
/*void reverseArray(int arr[], int n)
{
    int l = 0, h = n - 1;

    // while (l < h)
    // {
    //     swap(arr[l], arr[h]);
    //     l++;
    //     h--;
    // }

    // Pro ki trh code
    // while (l < h)
    // swap(arr[l++], arr[h--]);

    while (l < h)
    {
        // swap(arr[l], arr[h]);
        arr[l] = arr[l] ^ arr[h];
        arr[h] = arr[h] ^ arr[l];
        arr[l] = arr[l] ^ arr[h];
        l++;
        h--;
    }
}

int main()
{
    int arr[7] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    // M1. custom reversal using 2-pointer approach
    reverseArray(arr, n);

    // M2. STL, C++ lib
    // reverse(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}*/

/*int main()
{
    // diff methods of swap

    // 1. swap inbuilt fn
    // int a = 5, b = 6;
    // swap(a, b);
    // cout << "a: =" << a << ", b:" << b << endl;

    // 2. temp variable
    // int a = 5, b = 6;
    // int temp = a; // temp will be 5
    // a = b; // a will be 6
    // b = temp; // b will be 5
    // cout << "a: =" << a << ", b:" << b << endl;

    // 3. arithematic method, interview question????????
    // int a = 5, b = 6;
    // a = a + b; // sum of a and b stored in a, a = 11, b = 6;
    // b = a - b; // subtracting b from new a gives initial value of a,, a = 11, b = 5
    // a = a - b; // subtract new b from new a gives initial value of b... a = 6, b = 5
    // cout << "a:" << a << ", b:" << b << endl;

    // 4. XOR bitwise method, interview question????????
    int a = 5, b = 6;
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    cout << "a:" << a << ", b:" << b << endl;
    return 0;
}*/