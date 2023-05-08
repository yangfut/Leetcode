#include <vector>

class Solution {
public:
    void decisionTree(int idx, vector<int>&subset, vector<vector<int>>&ans, vector<int>&nums){
        if(idx >= nums.size()){
            ans.push_back(subset);
            return;
        }

        //Left leaf
        subset.push_back(nums[idx]);
        decisionTree(idx+1, subset, ans, nums);
        subset.pop_back();


        //Right leaf
        //Skip duplicated element since it's done in left leaf
            while( idx+1 < nums.size() && nums[idx] == nums[idx+1]){
            ++idx;
        }
        decisionTree(idx+1, subset, ans, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>subset;
        decisionTree(0, subset, ans, nums);
        return ans;
    }
};

