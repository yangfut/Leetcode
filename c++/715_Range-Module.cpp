class RangeModule {
private:
    map<int,int> intervals;
    map<int,int>::iterator getInterval(int value){
        auto it = intervals.upper_bound(value);

        // check if previous interval includes value(a.k.a left)
        if((--it)->second < value) ++it;
        return it;
    }
public:
    RangeModule() {
        // add dummy pair
        intervals[INT_MIN] = INT_MIN;
    }
    
    void addRange(int left, int right) {
        auto it = getInterval(left);
        while(it != intervals.end() && it->first <= right){
            left = min(it->first, left);
            right = max(it->second, right);
            it = intervals.erase(it);
        }

        intervals[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = getInterval(left);
        return it != intervals.end() && it->first <= left && it->second >= right;
    }
    
    void removeRange(int left, int right) {
        auto it = getInterval(left);
        pair<int,int> remains[2];

        while(it != intervals.end() && it->first < right){
            if(it->first < left){
                remains[0] = make_pair(it->first, left);
            }

            if(it->second > right){
                remains[1] = make_pair(right, it->second);
            }

            it = intervals.erase(it);
        }

        intervals[remains[0].first] = remains[0].second;
        intervals[remains[1].first] = remains[1].second;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */