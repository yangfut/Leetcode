class Solution {
public:
    void backtracking(vector<int>& candidates, int target, int idx, vector<int>& subSum, vector<vector<int>>& result){
        if(target == 0) result.push_back(subSum);
        if(idx == candidates.size() || target < candidates[idx]) return;

        // Pick
        subSum.push_back(candidates[idx]);
        backtracking(candidates, target-candidates[idx], idx+1, subSum, result);
        subSum.pop_back();

        while(idx+1<candidates.size() && candidates[idx]==candidates[idx+1]) ++idx;
        // Not pick
        backtracking(candidates, target, idx+1, subSum, result);        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> subSum;
        vector<vector<int>> result;

        backtracking(candidates, target, 0, subSum, result);
        return result;
    }
};