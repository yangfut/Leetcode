// Time Limit Exceeded
// TC: O(N^2), SC: O(N)
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n,0);
        for(int i = 0; i < n; ++i){
            int curr = 0;
            unordered_set<int> seen;
            for(int j = i; j < n; ++j){
                seen.insert(nums[j]);
                if(seen.size() == k) ++curr;
                dp[j] += curr;
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    int atMost(int k, vector<int>& nums){
        int n = nums.size();
        int res = 0;
        unordered_map<int,int> freq;
        for(int lhs = 0, rhs = 0; rhs < n; ++rhs){
            if(freq[nums[rhs]]++ == 0){
                --k;
            }

            // over elements in the window
            while(k < 0){
                if(--freq[nums[lhs]] == 0){
                    ++k;
                }
                ++lhs;
            }

            // Count subarray number
            res += (rhs - lhs + 1);
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(k,nums) - atMost(k-1,nums);
    }
};