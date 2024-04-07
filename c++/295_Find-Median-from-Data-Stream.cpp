class MedianFinder {
private:
    priority_queue<int> maxHeap; // Store values before median
    priority_queue<int, vector<int>, greater<int>> minHeap; // Store values after median
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size()==0 || num<maxHeap.top()) maxHeap.push(num);
        else minHeap.push(num);

        if(minHeap.size() > maxHeap.size() + 1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if((maxHeap.size()==minHeap.size())){
            return (maxHeap.top()+minHeap.top()) / 2.0;
        }
        
        if(maxHeap.size() > minHeap.size()) return maxHeap.top();
        else return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

class MedianFinder {
private:
    priority_queue<int> maxHeap; // Store values before median
    priority_queue<int, vector<int>, greater<int>> minHeap; // Store values after median
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Balance maxHeap and minHeap
        if(minHeap.size()-maxHeap.size()>1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if((maxHeap.size()+minHeap.size())%2==0){
            return (maxHeap.top()+minHeap.top()) / 2.0;
        }
        return (double) minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */