class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int bk = -1, n = nums.size();
        for(int i = n-2, j = n-1; i >= 0; --i, --j){
            if(nums[i] < nums[j]) {
                bk = i;
                break;
            }
        }
        if(bk != -1){
            // next greater element
            int idx = bk + 1, nge = INT_MAX;
            for(int i = bk + 1; i < n; ++i){
                if(nums[i] < nge && nums[i] > nums[bk]){
                    nge = nums[i];
                    idx = i;
                }
            }
            swap(nums[bk], nums[idx]);
        }

        sort(nums.begin() + bk + 1, nums.end());
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int bk = -1, n = nums.size();
        for(int i = n-2, j = n-1; i >= 0; --i, --j){
            // break if not deceding
            if(nums[i] < nums[j]) {
                bk = i;
                break;
            }
        }
        if(bk != -1){
            // Find next minimum value in decending array
            for(int i = n-1 ; i > bk; --i){
                if(nums[i] > nums[bk]){
                    swap(nums[bk], nums[i]);
                    break;
                }
            }
            
        }

        reverse(nums.begin() + bk + 1, nums.end());
    }
};