class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0, sum = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            if(i >= 3){
                sum -= nums[i-3];
            }

            if(nums[i] == 0){
                if(sum %2 == 0){
                    ++sum;
                    nums[i] = 1;
                }else{
                    nums[i] = 0;
                }
            }else{
                if(sum % 2 == 1){
                    ++sum;
                    nums[i] = 1;
                }else{
                    nums[i] = 0;
                }
            }
            if(i > n-3 && nums[i] == 1) return -1;
            ops += nums[i];
        }
        return ops;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0, n = nums.size();
        for(int i = 0; i <= n-3; ++i){
            if(nums[i] == 0){
                // flip
                nums[i] ^= 1;
                nums[i+1] ^= 1;
                nums[i+2] ^= 1;
                ++ops;
            }
        }
        if(nums[n-2] == 1 && nums[n-1] == 1) return ops;
        return -1;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0, flips = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            if(i >= 3) flips -= nums[i-3];

            int curr = nums[i] + flips;
            if(curr % 2 == 0){
                ++flips;
                nums[i] = 1;
            }else{
                nums[i] = 0;
            }
            ops += nums[i];
        }
        if(nums[n-2] == 1 || nums[n-1] == 1) return -1;
        return ops;
    }
};