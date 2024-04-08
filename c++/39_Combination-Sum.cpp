class Solution {
public:
    void dfs(vector<int>& candidates, int target, int idx, vector<int>& buff, vector<vector<int>>& result){
        if(target==0) result.push_back(buff);
        if(idx == candidates.size() || target < candidates[idx]) return;

        //Pick
        buff.push_back(candidates[idx]);
        dfs(candidates, target-candidates[idx], idx, buff, result);
        buff.pop_back();

        //Not Pick
        dfs(candidates, target, idx+1, buff, result);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> buff;
        dfs(candidates, target, 0, buff, result);
        return result;
    }
};