#define ll long long
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        ll sum = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<ll> preSum(n, nums.front());
        for(int i = 1; i < n; ++i){
            preSum[i] = nums[i] + preSum[i-1];
        }

        for(int i = n-1; i >= 2; --i){
            if(preSum[i-1] > static_cast<ll>(nums[i])) return preSum[i-1] + nums[i];
        }
        return -1;
    }
};

#define ll long long
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        ll sum = 0, res = -1;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            if(sum > nums[i]){
                res = sum + nums[i];
            }

            sum += nums[i];
        }
        return res;
    }
};