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