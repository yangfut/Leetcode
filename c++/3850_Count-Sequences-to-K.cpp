class Solution {
public:
    long long gcd(long long a, long long b){
        return b == 0 ? a : gcd(b, a%b);
    }
    pair<long long,long long> mul(long long num, long long denom, const vector<int>& nums, const int idx){
        num *= nums[idx];
        return {num, denom};
    }

    pair<long long,long long> div(long long num, long long denom, const vector<int>& nums, const int idx){
        denom *= nums[idx];
        return {num, denom};
    }

    int dfs(long long num, long long denom, const vector<int>& nums, const int idx, long long k, map<tuple<long long, long long, long long>, int>& memo){
        if(idx == nums.size() && num % denom == 0 && num / denom == k) return 1;
        if(idx == nums.size()) return 0;

        long long base = gcd(num, denom);
        num /= base;
        denom /= base;

        auto key = make_tuple(num, denom, idx);
        if(memo.count(key)) return memo[key];

        auto [mulValN, mulValD] = mul(num, denom, nums, idx);
        auto [divValN, divValD] = div(num, denom, nums, idx);

        int countMul = dfs(mulValN, mulValD, nums, idx+1, k, memo);
        int countDiv = dfs(divValN, divValD, nums, idx+1, k, memo);
        int countUnc = dfs(num, denom, nums, idx+1, k, memo);
        return memo[key] = countMul + countDiv + countUnc;
    }
    int countSequences(vector<int>& nums, long long k) {
        // dfs
        map<tuple<long long, long long, long long>, int> memo;
        return dfs(1, 1, nums, 0, k, memo);
        
    }
};