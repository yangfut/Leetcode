class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int table[60001] = {0};
        int offset = 30000;
        int ans = 0;
        for(int ele:nums){
            table[ele+offset]++;
        }

        for(int idx=0; idx<60001; idx++){
            if(table[idx]==1){
                ans = idx-offset;
                break;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // hash table: TC:O(N+MAX_VALUE)
        // bitset<600001> bits;
        
        // for(int& num : nums){
        //     bits.flip(num+30000);
        // }
        // int ans;
        // for(int i = bits.size(); i >= 0; --i){
        //     if(bits[i] == 1) ans = i;
        // }
        // return ans - 30000;

        // XOR: TC:O(N)
        int ans = nums[0];
        for(int i = 1; i < nums.size(); ++i) ans = ans ^ nums[i];
        return ans;
    }
};