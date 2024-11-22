class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> rSum(n, nums.back());
        vector<int> lSum(n, nums.front());
        for(int i = 1; i < n; ++i){
            lSum[i] = lSum[i-1]+nums[i];
        }
        for(int i = n-2; i >= 0; --i){
            rSum[i] = rSum[i+1]+nums[i];
        }
        vector<int> output(n, 0);
        for(int i = 0; i < n; ++i){
            int rr = (i+1 == n) ? 0 : rSum[i+1];
            int ll = (i-1 < 0) ? 0 : lSum[i-1];
            // cout << rr << " " << ll << " " << nums[i] << endl;
            output[i] = (rr - (n-1-i)*nums[i]) + ((i-0)*nums[i] - ll);
        }
        return output;
    }
};