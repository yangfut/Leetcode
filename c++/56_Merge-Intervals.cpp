class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>vec;
        for(int i=0;i<intervals.size();i++){
            //Non-overlap OR first interval
            if(vec.empty()||vec.back()[1]<intervals[i][0]) vec.push_back(intervals[i]);
            //Overlap
            else vec.back()[1]=max(intervals[i][1], vec.back()[1]);
        }
        return vec; 
    }
};