class MyCalendar {
public:
    map<int,int> bookTime;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto hi = bookTime.lower_bound(startTime);
        int rStartTime = INT_MAX, lEndTime = -1;
        if(hi != bookTime.end()) rStartTime = hi->first;
        if(hi != bookTime.begin()) lEndTime = prev(hi)->second;
        if(lEndTime > startTime || rStartTime < endTime) return false;

        bookTime[startTime] = endTime;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */