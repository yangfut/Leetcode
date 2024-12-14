class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            if(nums[i] == 0) nums[i] = -1;
        }

        int sum = 0, res = 0;
        unordered_map<int,int> record;
        record[0] = -1;
        for(int i = 0; i < n; ++i){
            sum += nums[i];

            if(record.find(sum) == record.end()) record[sum] = i;
            else res = max(res, i - record[sum]);
        }
        return res;
        
    }
};