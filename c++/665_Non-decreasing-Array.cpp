class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        vector<int> p;
        for(int i = 1; i < n; ++i){
            if(nums[i] >= nums[i-1]) continue;

            if(p.size() > 0) return false;
            p.push_back(i);
        }

        if(p.size() == 0 || p[0] == 1 || p[0] == n-1) return true;

        int idx = p[0];
        return nums[idx-2] <= nums[idx] || nums[idx-1] <= nums[idx+1];
    }
};