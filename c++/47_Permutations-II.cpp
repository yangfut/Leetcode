#include <vector>
#include <map>
class Solution {
public:
    void backtrack(vector<vector<int>>&ans, vector<int>&buff, unordered_map<int, int>&isUsed, vector<int>&nums){
        if(buff.size() == nums.size()){
            ans.push_back(buff);
            return;
        }
        vector<bool>isDuplicated(21, false);
        int offset = 10;

        for(int idx = 0; idx < nums.size(); ++idx){
            if(isUsed[nums[idx]] == 0) continue;
            if(isDuplicated[nums[idx]+offset] == false){
                isDuplicated[nums[idx]+offset] = true;
                --isUsed[nums[idx]];
                buff.push_back(nums[idx]);
                backtrack(ans, buff, isUsed, nums);
                ++isUsed[nums[idx]];
                buff.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>buff;
        unordered_map<int, int>isUsed;
        for(int ele : nums){
            if(isUsed.find(ele) == isUsed.end()){
                isUsed.insert({ele, 1});
            }else{
                ++isUsed[ele];
            }
        }
        backtrack(ans, buff, isUsed, nums);
        return ans;
    }
};

