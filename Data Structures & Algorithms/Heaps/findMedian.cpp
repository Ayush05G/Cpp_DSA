class MedianFinder {
public:
        priority_queue<int> maxHeap;
        priority_queue<int,vector<int>, greater<int> > minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size() == minHeap.size()) {
            if(num > findMedian()) {
                //insert in right
                minHeap.push(num);
               
            }
            else {
                //insert in left;
                maxHeap.push(num);
               
            }
        }
        else if(maxHeap.size() == minHeap.size() + 1) {
            //maxHeap ka size bada h as compared to minheap by 1 
            if(num > findMedian() ){
                //insert in right
                minHeap.push(num);
            }
            else {
                //insert in left
                //max already bada h seedha insert nahi kr skte, toh 1 element offload karo 
                int element = maxHeap.top();
                maxHeap.pop();
                minHeap.push(element);
                ////now insert num in left
                maxHeap.push(num);
                
            }
        }
        else if(maxHeap.size()+1 == minHeap.size()) {
            //minheap ka size bada h as compared to maxheap by 1 
            if(num > findMedian()) {
                //insert in right
                //min already bada h seedha insert nahi kr skte, toh 1 element offload karo 
                int element = minHeap.top();
                minHeap.pop();
                maxHeap.push(element);
                //now insert num in right 
                minHeap.push(num);
                
            }
            else {
                //insert in left
                maxHeap.push(num);
                
            }
        }
    }
    
    double findMedian() {
        if(minHeap.size() == 0 &&  maxHeap.size() == 0) {
            return 0;
        }
        else if(minHeap.size() == maxHeap.size()) {
            return (minHeap.top() + maxHeap.top())/2.0;
        }
        else if(minHeap.size() == maxHeap.size() + 1) {
            return minHeap.top();
        }
        else if(minHeap.size()+1 == maxHeap.size()) {
            return maxHeap.top();
        }
        else {
            return -1;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */