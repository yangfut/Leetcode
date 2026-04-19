class MyCalendarTwo {
public:
    map<int,int> eventDiff;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        eventDiff[startTime] += 1;
        eventDiff[endTime] -= 1;
        int count = 0;
        for(auto& [time, diff] : eventDiff){
            count += diff;
            if(count >= 3){
                eventDiff[startTime] -= 1;
                eventDiff[endTime] += 1;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */

 class MyCalendarTwo {
public:
    vector<pair<int,int>> singles;
    vector<pair<int,int>> doubles;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        
        for(auto& [st, ed] : doubles){
            // check overlaps 
            int lo = max(st, startTime);
            int hi = min(ed, endTime);
            if(lo < hi) return false;
        }

        for(auto& [st, ed] : singles){
            // find any overlaps
            int lo = max(st, startTime);
            int hi = min(ed, endTime);
            if(lo < hi) doubles.emplace_back(lo, hi);
        }

        singles.emplace_back(startTime, endTime);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */