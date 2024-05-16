class MKAverage {
private:
    int m, k;
    long sum;
    std::multiset<int> topKSmall;
    std::multiset<int> topKBig;
    std::multiset<int> middle;
    std::deque<int> deq;

public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
        sum = 0;
    }
    
    void addElement(int num) {
        // If queue is full, remove the oldest
        if(deq.size() == m){
            int value = deq.front();
            deq.pop_front();

            if(topKBig.find(value) != topKBig.end()){
                topKBig.erase(topKBig.find(value));

                auto it = std::prev(middle.end());
                topKBig.insert(*it);
                sum -= *it;
                middle.erase(it);
            }else if(topKSmall.find(value) != topKSmall.end()){
                topKSmall.erase(topKSmall.find(value));
                
                auto it = middle.begin();
                topKSmall.insert(*it);
                sum -= *it;
                middle.erase(it);
            }else{
                sum-=value;
                middle.erase(middle.find(value));
            }
        }

        // Add the new element to queue
        deq.push_back(num);

        // Adjust multiset structures to accommodate the new element
        if(topKBig.size() < k) topKBig.insert(num);
        else{
            topKBig.insert(num);
            auto it = topKBig.begin();
            int numToMove = *it;
            topKBig.erase(it);
            topKSmall.insert(numToMove);

            if(topKSmall.size() > k){
                it = std::prev(topKSmall.end());
                numToMove = *it;
                topKSmall.erase(it);
                middle.insert(numToMove);
                sum += numToMove;
            }

        }
    }
    
    int calculateMKAverage() {
        if(deq.size() < m) return -1;

        return sum / (middle.size());
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */

class MKAverage {
private:
    int m, k;
    multiset<int> topKSmall, topKBig, middle;
    deque<int> deq;
    long sum;
public:
    MKAverage(int _m, int _k) {
        m = _m;
        k = _k;
        sum = 0;
    }

    ~MKAverage(){

    }

    void addElement(int num) {
        
        if(deq.size() == m){
            int numToRemove = deq.front();
            deq.pop_front();

            if(numToRemove <= *prev(topKSmall.end())){
                auto it = topKSmall.find(numToRemove);
                topKSmall.erase(it);
                it = middle.begin();
                topKSmall.insert(*it);
                sum -= *it;
                middle.erase(it);
            }else if(numToRemove >= *topKBig.begin()){
                auto it = topKBig.find(numToRemove);
                topKBig.erase(it);
                it = prev(middle.end());
                topKBig.insert(*it);
                sum -= *it;
                middle.erase(it);
            }else{
                sum -= numToRemove;
                middle.erase(numToRemove);
            }
        }

        deq.push_back(num);

        // Adjust multiset structures to accommodate the new element
        topKSmall.insert(num);
        if(topKSmall.size() <= k) return;

        // take the last element to topKBig
        auto it = prev(topKSmall.end());
        topKBig.insert(*it);
        topKSmall.erase(it);
        if(topKBig.size() <= k) return;
        
        // take the first element to middle
        it = topKBig.begin();
        middle.insert(*it);
        sum += *it;
        topKBig.erase(it);
    }
    
    int calculateMKAverage() {
        if(deq.size() < m) return -1;
        return sum / static_cast<long>(m-2*k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */