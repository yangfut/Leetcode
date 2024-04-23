class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return (a[0] == b[0]) ? a[1] < b[1] : a[0] < b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Edge case: empty intervals
        if(intervals.empty()) return {newInterval};

        //Edge case: newInterval is at the end
        if(newInterval[0] > intervals.back()[1]){
            intervals.push_back(newInterval);
            return intervals;
        }
        int n = intervals.size();
        for(int i=0; i<n; ++i){
            if(newInterval[0] <= intervals[i][1]){
                intervals.insert(intervals.begin()+i, newInterval);
                break;
            }
        }

        vector<vector<int>> merge;
        merge.push_back(intervals[0]);
        for(int i=1; i<n+1; ++i){
            if(merge.back()[1] < intervals[i][0]){
                merge.push_back(intervals[i]);
            }else{
                merge.back()[1] = max(merge.back()[1], intervals[i][1]);
                merge.back()[0] = min(merge.back()[0], intervals[i][0]);
            }
        }

        return merge;
    }
};