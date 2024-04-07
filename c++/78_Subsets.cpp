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

class Solution {
public:
    void backtracking(vector<int>& nums, int idx, vector<int>& buffer, vector<vector<int>>& result){
        if(idx == nums.size()){
            result.push_back(buffer);
            return;
        }

        // Pick
        buffer.push_back(nums[idx]);
        backtracking(nums, idx+1, buffer, result);

        // Not Pick
        buffer.pop_back();
        backtracking(nums, idx+1, buffer, result);


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> buffer;
        backtracking(nums, 0, buffer, result);
        return result;
    }
};