#include <vector>

class Solution {
public:
    void backtrack(vector<vector<int>>&ans, vector<int>&buff, vector<bool>&isUsed, vector<int>&nums){
        if(buff.size() == nums.size()){
            ans.push_back(buff);
            return;
        }
            
            for(int idx = 0; idx < nums.size(); ++idx){
                if(isUsed[idx]) continue;
                isUsed[idx] = true;
                buff.push_back(nums[idx]);
                backtrack(ans, buff, isUsed, nums);
                isUsed[idx] = false;
                buff.pop_back();
            }
    }

    vector<vector<int>> permute(vector<int>& nums) {
		if(nums.size() == 1) return {nums};
		vector<bool>isUsed(nums.size(), false);
		vector<vector<int>>ans;
        vector<int>buff;
		
		backtrack(ans, buff, isUsed, nums);
		return ans;
    }
};

class Solution {
public:
    void backtracking(vector<int>& nums, vector<int>& buff, vector<int>& visited, vector<vector<int>>& result){
        if(buff.size()==nums.size()){
            result.push_back(buff);
            return;
        }

        for(int idx=0; idx<nums.size();++idx){
            if(visited[idx]==1) continue;
            visited[idx]=1;
            buff.push_back(nums[idx]);
            backtracking(nums, buff, visited, result);
            visited[idx]=0;
            buff.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> visited(nums.size(), 0);
        vector<int> buff;
        backtracking(nums, buff, visited, result);
        return result;
    }
};