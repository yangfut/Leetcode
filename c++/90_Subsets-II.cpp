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

class Solution {
public:
    void backtracking(vector<int>&nums, int idx, vector<int>& subset, vector<vector<int>>& subset_vec){
        if(idx==nums.size()){
            subset_vec.push_back(subset);
            return;
        }

        // Pick
        subset.push_back(nums[idx]);
        backtracking(nums, idx+1, subset, subset_vec);
        subset.pop_back();

        // Not pick and avoid duplicated subset appearing
        while(idx+1<nums.size()&&nums[idx]==nums[idx+1]) ++idx;
        backtracking(nums, idx+1, subset, subset_vec);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>subset_vec;
        vector<int>subset;
        backtracking(nums, 0, subset, subset_vec);
        return subset_vec;
    }
};

class Solution {
public:
    void backtracking(vector<int>&nums, int idx, multiset<int>& subset, set<multiset<int>>&st){
        if(idx==nums.size()){
            st.insert(subset);
            return;
        }

        // Not Pick
        backtracking(nums, idx+1, subset, st);

        // Pick
        subset.insert(nums[idx]);
        backtracking(nums, idx+1, subset, st);
        subset.erase(subset.find(nums[idx])); // remove the first element was found
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<multiset<int>>st;
        multiset<int>subset;
        backtracking(nums, 0, subset, st);
        vector<vector<int>> ans;
        
        for(auto it=st.begin();it!=st.end();++it){
            vector<int> temp;
            for(auto ele=it->begin();ele!=it->end();++ele) temp.push_back(*ele);
            ans.push_back(temp);
        }
        return ans;
    }
};
