class RecentCounter {
public:
    queue<int> valid_recent;
    RecentCounter() {
    }
    
    int ping(int t) {
        valid_recent.push(t);
        while(valid_recent.front() < (t-3000)){
            valid_recent.pop();
        }

        return valid_recent.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */