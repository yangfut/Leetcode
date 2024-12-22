class Solution {
    void _dfs(const int idx, const vector<int> &nums, vector<int> &subseq, vector<vector<int>> &res){
        if(subseq.size() >= 2) res.push_back(subseq);

        unordered_set<int> appear;
        for(int i = idx; i < nums.size(); ++i){
            
            if(appear.find(nums[i]) != appear.end()) continue;
            if(!subseq.empty() && nums[i] < subseq.back()) continue;

            appear.insert(nums[i]);
            subseq.push_back(nums[i]);
            _dfs(i+1, nums, subseq, res);
            subseq.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subseq;
        int n = nums.size();
        _dfs(0, nums, subseq, res);
        return res;
    }
};