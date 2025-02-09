#include<iostream>
#include<vector>
using namespace std;

// int max(int a, int b) {
//     if(a > b) {
//         return a;
//     }
//     else {
//         return b;
//     }
// }


void printAllEvens(int arr[],int n, int index) {
    //base case
    if(index == n) {
        return;
    }

    //1 acse main
    if( !(arr[index]&1) ) {
        cout << arr[index] << " ";
    }
    //baaki recursion
    printAllEvens(arr,n,index+1);
}

void printAllOdds(int arr[], int n, int index, vector<int> &ans) {
    //base case
    if(index == n) {
        return;
    }
    //1 case main
    if((arr[index])&1 ) {
        ans.push_back(arr[index]);
        //cout << arr[index] << ' ';
    }
    //baaki recursion karega
    printAllOdds(arr,n,index+1,ans);
}


void minInArray(int arr[], int size,int index, int &mini) {
    //base case
    if(index == size) {
        return;       
    }
    //1 case main 
    mini = min(mini, arr[index]);
    //baaki recursion
    minInArray(arr,size,index+1, mini);
}


void maxInArray(int arr[], int size,int index, int &maxi) {
    //base case
    if(index == size) {
        //entire array traverse kr chuka hu
        return;
    }
    //recursive relation
    //1 case mera
    //processing
    maxi = max( maxi, arr[index]);
    //baaki recursion
    maxInArray(arr,size, index+1, maxi);
    
}


bool searchInArray(int arr[], int size,int index, int target) {
    //base case
    //2 base case -> found / not found
    //nopt found
    if(index >= size) {
        //invalid index -> out of bounds of array
        return false;
    }
    //found -> 1 case
    if(arr[index] == target) {
        return true;
    }
    //recursive relation -> baaki cases
    bool ans = searchInArray(arr,size,index+1, target);
    return ans;
}



void printArray(int arr[], int size, int index) {
    //base case
    if(index == size) {
        //array se bahar aagye ho
        return ;
    }
    //recursive relation
    //1 case main solve karunga
    cout << arr[index] << " ";
    //baaki recursion sambhal lega
    printArray(arr, size, index+1);
}


// void printArray(int arr[], int size, int index) {
//     //base case
//     if(index == size) {
//         return ;
//     }
//     cout << arr[index] << " ";
//     printArray(arr, size, index+1);
// }

int main() {

    int arr[] = {10,11,12,13,14,15,16};
    int size = 7;
    int index  = 0;
    vector<int> ans;
    printAllOdds(arr,size,index,ans);

    //printing ans
    for(auto num: ans) {
        cout << num << " ";
    }

    // int arr[] = {10,20,30, 40, 50, 60};
    // int size = 6;
    // int index = 0;
    // int mini = INT_MAX;
    // minInArray(arr,size,index,mini);
    // // int maxi = INT_MIN;
    // // maxInArray(arr,size,index,maxi);
    // cout << "Min no-> " << mini << endl;

    // int target = 500;
    // cout << searchInArray(arr,size,index,target) << endl;
    // int index = 0;
    // printArray(arr,size,index);





    return 0;
}