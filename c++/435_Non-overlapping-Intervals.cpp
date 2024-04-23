class Solution {
public:
    static bool cmp(const vector<int>& a, vector<int>& b){
        return (a[1] == b[1]) ? a[0] < b[0] : a[1] < b[1];
    }

    // Questions: which one is better? sort by starti or endi
    // Answer: sort by endi

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 1. Sort by intervals[1]
        // 2. Compare current start with previous end
        // 3. Remove this current if overlapping
        sort(intervals.begin(), intervals.end(), cmp);
        int prevEnd = INT_MIN, removedCount = 0;
        for(vector<int>& intv : intervals){
            if(intv[0] >= prevEnd){
                prevEnd = intv[1];
            }else{
                ++removedCount;
            }
        }
        return removedCount;
    }
};