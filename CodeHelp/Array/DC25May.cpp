// Single number
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         // 1. sorting
//         // sort(start_add, start_add + n); -> int arr[]

//         // vector
//         sort(nums.begin(), nums.end()); // vector inc.

//         int n = nums.size();
//         int ans = -1;
//         int i = 0;
//         while(i < n){
//             if(i + 1 < n && nums[i] == nums[i + 1])
//                 i += 2;
//             else {
//                 ans = nums[i];
//                 break;
//             }
//         }
//         return ans;
//     }
// };

// Rotate an array
// class Solution {
// public:
//     // void reverse(vector<int>&nums, int l, int h){
//     //     // l-> h reverse using swap.
//     // }

//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k = k % n; //

//         // 1 2 3 4 5 6 7 -

//         // 1. reverse all
//         reverse(nums.begin(), nums.end()); // (start_add, end_add+1)

//         // 2. reverse first k
//         reverse(nums.begin(), nums.begin() + k);

//         // 3. reverse first n-k
//         reverse(nums.begin() + k, nums.end());
//     }
// };

// Sort 0's 1's
// void segregate0and1(int arr[], int n) {
//         int l = 0, h = n - 1; // 2 indices
//         while(l < h){
//             if(arr[l] == 1 && arr[h] == 0){
//                 // swap case
//                 swap(arr[l], arr[h]);
//                 l++, h--;
//             }
//             else{
//                 if(arr[l] == 0)
//                     l++;
//                 if (arr[h] == 1)
//                     h--;
//             }
//         }
//     }


// pair and fill
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
    // pair<datatype1, dt2> name;

    // pair<int,char>A;
    // pair<int,char>A(4, 't');
    // pair<int,char>A = {4, 't'};
    // pair<int,char>A = make_pair(4, 't');

    // access
    // cout<< A.first << " "<<A.second<<endl;

    // How to use fill in 2-D array
    int arr[4][3] = {{1,2,3},{5,6,7},{9,10,11},{12,13,14}};

    // fill
    fill(&arr[0][0], &arr[0][0] + (4 * 3), -1);

    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}