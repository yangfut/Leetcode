#define MOD 1000000007
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> pwr(n,1);
        for(int i = 1; i < n; ++i){
            pwr[i] = (pwr[i-1] * 2) % MOD;
        }

        int count = 0, st = 0, ed = n-1;

        // binary search
        while(st <= ed){
            if(nums[st] + nums[ed] <= target){
                count = (count + pwr[ed-st]) % MOD;
                ++st;
            }else{
                --ed;
            }
        }

        return count;
    }
};