// DP
// TC:O(N), SC:O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // #1 0D Dynamic Programming(tabulation)
        int maxt = -10000, maxv = -10000;

        for(int& num : nums){
            maxt = max(maxt+num, num);
            maxv = max(maxt, maxv);
        }
        return maxv;
    }
};

// Sliding window
// TC: O(N), SC: O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        for(int i = 0; i < n; ++i) prefix[i+1] = prefix[i] + nums[i];

        deque<int> deq;
        deq.push_back(0);
        int res = INT_MIN;

        // Maximum subarray[i:j] = maximum of prefix[j] - prefix[i]
        for(int i = 1; i <= n; ++i){
            res = max(res, prefix[i] - prefix[deq.front()]);
            while(!deq.empty() && prefix[i] < prefix[deq.back()]) deq.pop_back();
            deq.push_back(i);
        }
        return res;
    }
};