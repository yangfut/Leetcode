class Solution {
public:
    //Backtrack
    void backtrack(vector<int>& nums, vector<int>&visited, vector<int> &temp, vector<vector<int>> &ans){
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int idx=0; idx<nums.size(); idx++){
            if(!visited[idx]){
                temp.push_back(nums[idx]);
                visited[idx] = true;
                backtrack(nums, visited, temp, ans);
                temp.pop_back();
                visited[idx] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp;
        vector<int>visited(nums.size(), false);
        
        backtrack(nums, visited, temp, ans);
        return ans;
    }
    
};