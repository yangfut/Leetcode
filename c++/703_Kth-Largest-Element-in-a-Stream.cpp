class KthLargest {
public:
    int capacity;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    KthLargest(int k, vector<int>& nums) {
        capacity = k;
        for(int idx=0;idx<nums.size();++idx) min_heap.push(nums[idx]);
        while(min_heap.size()>k) min_heap.pop();
    }
    
    int add(int val) {
        min_heap.push(val);
        if(min_heap.size()>capacity) min_heap.pop();
        return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */