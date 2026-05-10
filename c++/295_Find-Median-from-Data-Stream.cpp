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

 class MedianFinder {
public:
    multiset<int> ms;
    multiset<int>::iterator medIt = ms.end();
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        ms.insert(num);
        if(ms.size() == 1){
            medIt = ms.begin();
            return;
        }

        int medVal = *medIt;
        if(num < medVal && ms.size() % 2 == 0){
            // new value at left leaf && odd -> even
            --medIt;
        }else if(num >= medVal && ms.size() % 2 == 1){
            // new value at right leaf && even -> odd
            ++medIt;
        }
    }
    
    double findMedian() {
        if(ms.size() % 2 == 1) return *medIt;
        return (*medIt + *next(medIt)) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */