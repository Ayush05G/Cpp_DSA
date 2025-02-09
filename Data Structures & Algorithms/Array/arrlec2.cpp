#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int findUniqueNumber(int arr[] , int n) {
    int ans = 0 ;

    //to find the final answer, we need to XOR all the numbers in the array
    for(int i=0; i<n; i++) {
        ans = ans ^ arr[i];
    }
    return ans;

}

void sortZeroOne(int arr[], int n) {
    int zeroCount = 0;
    int oneCount = 0;
    //counting
    for(int i=0; i<n; i++) {
        if(arr[i] == 0) {
            zeroCount++;
        }
        if(arr[i] == 1) {
            oneCount++;
        }
    }
    //insertion
    fill(arr, arr+zeroCount, 0);
    fill(arr+zeroCount, arr+n, 1);
    
    // for(int i=0;i<zeroCount; i++) {
    //     arr[i] = 0;
    // }
    // for(int i=zeroCount; i<n; i++) {
    //     arr[i] = 1;
    // }
}

void printAllPairs(int arr[], int n) {
    for(int i=0; i<n; i++) {
        //for every i, we are running looping variable "j" from start to end
        for(int j=0; j<n; j++){
            cout << arr[i] <<", " << arr[j] << endl;
        }
    }
}

pair<int,int> checkTwoSum(int arr[], int n, int target) {
    //assuming (-1,-1) as no answer found
    pair<int,int> ans = make_pair(-1,-1);
    //check all pairs
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i] + arr[j] == target) {
                //found a pair that sums to target
                ans.first = arr[i];
                ans.second = arr[j];
                return ans;
            }
        }
    }
    //agar aap yha tak pohoch gye
    //iska matlab, koi bhi pair target k equal nahi mila
    //iska matlab return false karo
    return ans;
}

void checkTwoSumUsingArray(int arr[], int n, int target, int ans[]) {
    //assuming (-1,-1) as no answer found
    //pair<int,int> ans = make_pair(-1,-1);
    //check all pairs
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i] + arr[j] == target) {
                //found a pair that sums to target
                ans[0] = arr[i];
                ans[1] = arr[j];
                return ;
            }
        }
    }
    //agar aap yha tak pohoch gye
    //iska matlab, koi bhi pair target k equal nahi mila
    //iska matlab return false karo
    return ;
}

void checkTwoSumPrintAllAnswers(int arr[], int n, int target) {
    //assuming (-1,-1) as no answer found
    //pair<int,int> ans = make_pair(-1,-1);
    //check all pairs
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i] + arr[j] == target) {
                //found a pair that sums to target
                cout << arr[i] << ", " << arr[j] << endl;
            }
        }
    }
    //agar aap yha tak pohoch gye
    //iska matlab, koi bhi pair target k equal nahi mila
    //iska matlab return false karo
    return ;
}

void printAllTriplets(int arr[], int n) {
    int count = 0;
    //TC- > n^3
    //SC -> O(1) space
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                cout << arr[i] << ", " << arr[j] << ", " << arr[k] << endl;
                count++;
            }
        }
    }
    cout << "Total triplets printed: " << count << endl;
}

void checkThreeSum(int arr[], int n, int target) {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                if(arr[i] + arr[j] + arr[k] == target) {
                    //ans found
                    cout << arr[i] << ", " << arr[j] <<", " << arr[k] << endl;
                }
            }
        }
    }
}

void rotateArray(int arr[], int size, int n) {
    //size -> size of array
    //n -> refers to the number of elemnts by which we have to shift
    n = n % size;
    
    if(n == 0) {
        //no need to do anything
        return ;
    }

    //step1: copy last n elements into a temp array
    int temp[10000];
    int index = 0;
    for(int i = size-n; i<size; i++) {
        temp[index] = arr[i];
        index++;
    }

    //step2: shift array elemnts by finalShift places

    for(int i=size-1; i>=n; i--) {
        arr[i] = arr[i-n];
    }

    //step3: copy temp elements into original array 
    for(int i=0; i<n; i++) {
        arr[i] = temp[i];
    }

}

/* // Unique number
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //function complete krna h
        //vector -> array

        int ans = 0;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            ans = ans ^ nums[i];
        }
        //return kardo answer
        return ans;
    }
};*/
/* //Leetcode Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(nums[i] + nums[j] ==  target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};*/

int main() {
    int arr[] = {10,20,30,40,50,60};
    int size=6;
    //cyclically rotate array but 2 places
    int n = 0;
    cin>>n;

    cout << "Before: " << endl;
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    rotateArray(arr,size, n);

    //print array
    cout << "After: " << endl;
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    // int target = 70;
    // checkThreeSum(arr,n,target);
    //printAllTriplets(arr,n);


    // int target = 60;
    // checkTwoSumPrintAllAnswers(arr,n,target);

    // int ans[2] = {INT_MIN, INT_MIN};
    // int target = 60;
    // checkTwoSumUsingArray(arr,n,target,ans);

    // cout << ans[0] << " " << ans[1] << endl;

    // pair<int,int> ans = checkTwoSum(arr,n,600);
    // if(ans.first == -1 && ans.second == -1) {
    //     cout << "pair not found" << endl;
    // }
    // else {
    //     cout << "pair Found: " << ans.first << ", " << ans.second << endl;
    // }

    //printAllPairs(arr,n);

    // int arr[] = {0,1,1,1,0,0,1};
    // int size = 7;

    // //sortZeroOne(arr,size);
    // sort(arr,arr+size);

    // //printing the array
    // for(int i=0; i<size; i++) {
    //     cout << arr[i] << " ";
    // }

    // int ans  = findUniqueNumber(arr,size);
    // cout << "Unique number is: " << ans << endl;


    return 0;
}