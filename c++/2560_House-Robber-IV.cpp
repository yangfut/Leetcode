class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int val){
        bool canTake = true;
        int cnt = 0;
        for(int i = 0; i < nums.size(); ++i){

            if(nums[i] <= val){
                ++cnt;
                ++i; // skip the adjacent one
            }

            if(cnt >= k) return true;
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int ll = INT_MAX, hh = INT_MIN, ans = -1;
        for(int num : nums){
            ll = min(ll, num);
            hh = max(hh, num);
        }
        
        while(ll <= hh){
            int mid = (ll+hh)/2;
            if(isPossible(nums, k, mid)){
                ans = mid;
                hh = mid-1;
            }else{
                ll = mid+1;
            }
        }
        return ans;
    }
};