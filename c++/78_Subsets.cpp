#include <vector>

class Solution {
public:
    void decisionTree(int idx, vector<int>&subset, vector<vector<int>>&ans, vector<int>&nums){

        //Base case
        if( idx == nums.size()){
            ans.push_back(subset);
            return;
        }

        //Left leaf
        subset.push_back(nums[idx]);
        decisionTree(idx+1, subset, ans, nums);

        //Right leaf
        subset.pop_back();
        decisionTree(idx+1, subset, ans, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
            vector<int>subset;
            vector<vector<int>>ans;
            decisionTree(0, subset, ans, nums);
            return ans;
        }
};
