class Solution {
public:
    void backtrack(vector<int> &nums, int idx, vector<int>&temp, vector<vector<int>>&ans){
        if(idx >= nums.size()){
            ans.push_back(temp);
            return;
        }

        //Include iteself
        temp.push_back(nums[idx]);
        backtrack(nums, idx+1, temp, ans);
        temp.pop_back();

        //Exclude itself
        backtrack(nums, idx+1, temp, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int idx = 0;
        backtrack(nums, idx, temp, ans);
        return ans;
    }
};