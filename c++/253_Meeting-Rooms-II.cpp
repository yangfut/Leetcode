/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool cmp(Interval& a, Interval& b){
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        // edge cases
        if(intervals.size() <= 1) return intervals.size();

        // sort by starti
        sort(intervals.begin(), intervals.end(), cmp);

        // use mini heap to check earlest end time.
        priority_queue<int, vector<int>, greater<int>> endTime;

        for(const Interval& it : intervals){

            // If current interval can fit into earler schedule, remove the previous schedule
            if(!endTime.empty() && endTime.top() <= it.start){
                endTime.pop();
            }

            // If current interval can't fit, create other shcedule. 
            // If it can fit, creater other schedule since earlier one is removed.
            endTime.push(it.end);
        }

        return endTime.size();
    }
};

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool sortByStart(const Interval& a, const Interval& b){
        return a.start < b.start;
    }

    static bool sortByEnd(const Interval& a, const Interval& b){
        return a.end < b.end;
    }

    int minMeetingRooms(vector<Interval>& intervals) {

        // edge case
        if(intervals.size() < 1) return intervals.size();
        
        sort(intervals.begin(), intervals.end(), sortByStart);
        int n = intervals.size();
        vector<int> start(n);
        for(int i=0; i<n; ++i) start[i] = intervals[i].start;

        sort(intervals.begin(), intervals.end(), sortByEnd);

        int stIdx = 0, edIdx = 0, c = 0, minRooms = 0;

        while(stIdx < n && edIdx < n){

            if(start[stIdx] < intervals[edIdx].end){
                ++c;
                minRooms = max(minRooms, c);
                ++stIdx;
            }else{
                --c;
                ++edIdx;
            }
        }
        return minRooms;
    }
};
