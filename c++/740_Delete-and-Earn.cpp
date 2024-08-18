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