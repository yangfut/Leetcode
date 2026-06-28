class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // 1. Convert accumulated points for each value
        // 2. Consider accumulated points between dp[idx]+dp[idx-2] and dp[idx-1]

        int maxVal = 0;
        for(int num : nums) maxVal = max(maxVal, num);

        vector<int> dp(maxVal+1, 0);
        for(int num : nums) dp[num] += num;

        for(int i = 2; i < maxVal+1; ++i){
            dp[i] = max(dp[i-1], dp[i]+dp[i-2]);
        }
        return dp.back();

    }
};

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> count;
        for(int val : nums) ++count[val];

        vector<int> dp(count.size(), 0);
        auto it = count.begin();
        dp[0] = it->first * it->second;

        for(int i = 1; i < dp.size(); ++i){
            auto prev_it = it;
            ++it;
            int curr = it->first * it->second;
            if(it->first == prev_it->first + 1){
                dp[i] = (i>1) ? max(dp[i-2]+curr, dp[i-1]) : max(curr, dp[i-1]);
            }else{
                dp[i] = dp[i-1] + curr;
            }
        }
        return dp.back();

    }
};

// Hash Map solution
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> points;
        for(int val : nums) points[val] += val;

        for(auto it = points.begin(); it != points.end(); ++it){
            if(it == points.begin()) continue; //Skip the first elements
            int val = it->first;
            auto p = prev(it);
            int pp_val = (p == points.begin()) ? 0 : prev(p) -> second;

            if(p->first == val-1){
                it->second = max(p->second, pp_val + it->second);
            }else{
                it->second = p->second + it->second;
            }
        }
        return points.rbegin()->second;
    }
};

// Vector Solution
// array size: 10,001 integers = ~40KB  ← trivially small
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = INT_MIN;
        for(int val : nums) maxVal = max(val, maxVal);
        vector<int> dp(maxVal+1, 0);
        for(int val : nums) dp[val] += val;
        for(int i = 1; i < maxVal+1; ++i){
            int pprev = (i>1) ? dp[i-2] : 0;
            dp[i] = max(dp[i-1], pprev + dp[i]);
        }
        return dp.back();
    }
};