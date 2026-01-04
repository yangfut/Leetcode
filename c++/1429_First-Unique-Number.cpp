class FirstUnique {
public:

    queue<int> q;
    unordered_map<int,int> freq;

    FirstUnique(vector<int>& nums) {
        for(int num : nums){
            ++freq[num];
            if(freq[num] == 1) q.push(num);
        }
    }
    
    int showFirstUnique()x {
        while(!q.empty() && freq[q.front()] > 1) q.pop();
        return q.empty() ? -1 : q.front();
    }
    
    void add(int value) {
        ++freq[value];
        if(freq[value] == 1) q.push(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */