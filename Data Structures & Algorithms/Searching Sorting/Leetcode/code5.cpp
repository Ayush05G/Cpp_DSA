class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int s = 0;
        int n = arr.size();
        int e = n-1;
        int mid = s+(e-s)/2;

        while(s <= e) {
            //case 1: single element
            if(s == e) {
                return arr[s];
            }

            //mid index pr value 
            int currVal = arr[mid];
            //mid-1 index pr value, if exists
            int leftVal = -1;
            if(mid-1 >= 0) {
                leftVal = arr[mid-1];
            }
            //mid+1 index pr value, if exists
            int rightVal = -1;
            if(mid+1 < n) {
                rightVal = arr[mid+1];
            }

            //case 2: non duplicates
            if(currVal != leftVal && currVal != rightVal) {
                return currVal;
            }
            //case 3: left me duplicate mila 
            if(currVal == leftVal && currVal != rightVal) {
                int pairStartingIndex = mid-1;
                if(pairStartingIndex & 1) {
                    //agar index odd hua 
                    //standing on right part
                    //move to left
                    e = mid-1;
                }
                else {
                    //move to right
                    s = mid+1;
                }
            }//case 4: right me duplicate mila 
            else if(currVal != leftVal && currVal == rightVal) {
                int pairStartingIndex = mid;
                 if(pairStartingIndex & 1) {
                    //agar index odd hua 
                    //standing on right part
                    //move to left
                    e = mid-1;
                }
                else {
                    //move to right
                    s = mid+1;
                }
            }
            mid = s+(e-s)/2;
        }
        return -1;
    }
};