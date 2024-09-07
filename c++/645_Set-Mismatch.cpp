class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // #1 hash table
        int n = nums.size();
        int sum = 0;
        vector<int> hash_table(n+1,0);
        vector<int> ans(2,0);
        for(int num : nums){
            sum += num;
            if(hash_table[num] == 1) ans[0] = num;
            hash_table[num] = 1;
        }

        int corr = (1+n)*n/2;
        ans[1] = corr - (sum - ans[0]);

        return ans;
    }
};