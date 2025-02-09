class Solution {
public:
    void nextSmallerElement(vector<int>& arr, vector<int>& nextAns) {
        stack<int> st;
        st.push(-1);
        int n = arr.size();

        for(int i=n-1; i>=0; i--) {

            int element = arr[i];

            int index = st.top();
            while(index != -1 && arr[index] >= element) {
                st.pop();
            } 
            //agar yaha tk pohocha hu, iska mtlb
            //k ya toh koi choota number stack top pr h 
            //ya fer -1 stack top pr h 
            nextAns.push_back(st.top());
            //current number ko toh stack me push krna hi h 
            st.push(i);
        }
    }

    void prevSmallerElement(vector<int>& arr, vector<int>& prevAns) {
        stack<int> st;
        st.push(-1);
        int n = arr.size();

        for(int i=0; i<n; i++) {
            int element = arr[i];
            
            int stackTopIndex = st.top();
            
            while(stackTopIndex != -1 && arr[stackTopIndex] >= element) {
                st.pop();
            } 
            //agar yaha tk pohocha hu, iska mtlb
            //k ya toh koi choota number stack top pr h 
            //ya fer -1 stack top pr h 
            prevAns.push_back(st.top());
            //current number ko toh stack me push krna hi h 
            st.push(i);
        }
    }



    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextAns;
        vector<int> prevAns;
        nextSmallerElement(heights,nextAns);
        reverse(nextAns.begin(), nextAns.end());
        //yahi maoin bhul jata hu
        for(int i=0 ;i<nextAns.size(); i++) {
            if(nextAns[i] == -1) {
                nextAns[i] = nextAns.size(); 
            }
        }
        ///corner case -> = wala main bhul jata

        prevSmallerElement(heights, prevAns);

        int maxArea = INT_MIN;
        for(int i=0; i<nextAns.size(); i++) {
            int width = nextAns[i]-prevAns[i]-1;
            int height = heights[i];
            int currArea = width * height;
            maxArea = max(maxArea, currArea);
        }
        
        return maxArea;
    }
};