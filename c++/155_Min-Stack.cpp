#include <deque>
class MinStack {
public:
    deque<int>deq;
    MinStack() {
    }
    
    void push(int val) {
        deq.push_back(val);
        if(val<=deq.front()) deq.push_front(val);
    }
    
    void pop() {
        if(deq.back()==deq.front()) deq.pop_front();
        deq.pop_back();
    }
    
    int top() {
        return deq.back();
    }
    
    int getMin() {
        return deq.front();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */