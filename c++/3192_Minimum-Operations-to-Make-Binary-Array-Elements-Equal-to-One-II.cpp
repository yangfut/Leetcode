class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flips = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            if((nums[i] + flips) % 2 == 1){
                nums[i] = 0;
            }else{
                nums[i] = 1;
            }
            flips += nums[i];
        }
        return flips;
    }
};

// Improve division by using XOR operation to find odd/even number
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flips = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            // find odd: (nums[i] + flips) % 2 == 1
            // find odd: (nums[i] ^ flips) & 1 == 1

            // find even: (nums[i] + flips) % 2 == 0
            // find even: (nums[i] ^ flips) & 1 == 0
            if((nums[i] ^ flips) & 1){
                nums[i] = 0;
            }else{
                nums[i] = 1;
            }
            flips += nums[i];
        }
        return flips;
    }
};

// Remove the concept of window
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flips = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            if((nums[i] ^ flips) & 1) continue;
            ++flips;
        }
        return flips;
    }
};