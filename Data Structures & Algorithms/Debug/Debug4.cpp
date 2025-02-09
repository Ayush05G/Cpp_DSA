#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while(l <= r){
			int mid = l + (r-l)/2;
			if(nums[mid] == target) return mid;
			else if(nums[l]<=nums[mid]){
				if(nums[l]<=target && target<nums[mid]) r = mid-1;
				else l = mid+1;
			}
			else{
				if(nums[mid]<target && target<=nums[r]) l = mid+1;
				else r = mid-1;
			}
		}
		return -1;
	}

    int mySqrt(int x) {
        if (x == 0)
            return x;
        int first = 1, last = x;
        int mid = first + (last - first) / 2;
        while (first <= last) {
            if (mid  == x / mid)
                return mid;
            else if (mid > x / mid) {
                last = mid-1;
            }
            else {
                first = mid+1;
            }
            mid = first + (last - first) / 2;
        }
        return last;
    }

    // Question 3- Good one
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1, ans = start;
        while(nums[start] > nums[end]) {
            int mid = (start + end) >> 1;
            if(nums[mid] <= nums[start] && nums[mid] <= nums[end]) 
                end=mid;
            else if(nums[mid] >= nums[start] && nums[mid] >= nums[end])
                start=mid+1;          
            else return nums[mid];
            ans = start;
        }
        return nums[ans];
    }

    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid = (low + high) >> 1;
        while(low < high){
            int mid = (low + high) >> 1;
            if(nums[mid] >= nums[mid+1]){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }

    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]>ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                int index=lower_bound(ans.begin(), ans.end(), nums[i])-ans.begin(); // Before solving get acquainted with lower_bound()
                ans[index]=nums[i];
            }
        }    
        return ans.size();
    }

    void insertSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        
        if (left > 0 and nums[left-1] == target) {
            return left-1;
        } else {
            return -1;
        }
    }

int main() {

vector<int>nums = {10 ,20, 30, 40, 50, 60, 70, 80, 90, 100};
  int target=100;
  
//   int index= search(nums,target);
//   cout<<index;

// int mini=findMin(nums);
// cout<<mini;

// int peak=findPeakElement(nums);
// cout<<nums[peak];

// int length= lengthOfLIS(nums);
// cout<<length;

int search=binarySearch(nums,target);
cout<<search;

//   int x;
//   cin>>x;
//   int root=mySqrt(x);
//   cout<<root;

// int arr[]={80,90,100,70,60,50,40,30,20,10};
// int size=10;
// insertSort(arr,size);
//   for (int i = 0; i < size; ++i) {
//     cout << arr[i] << " ";
//   }
//   cout << endl;

  return 0;
}