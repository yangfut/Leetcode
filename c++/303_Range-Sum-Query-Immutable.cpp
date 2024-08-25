class NumArray {
public:
    vector<int> leftSum;
    vector<int> rightSum;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        int temp = 0;
        for(int i = 0; i < n; ++i){
            temp += nums[i];
            leftSum.push_back(temp);
            rightSum.push_back(temp);
        }

        for(int i = n-1; i >= 0; --i){
            rightSum[i] = temp - leftSum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        int left_excluded_value = (left > 0) ? leftSum[left-1] : 0;
        int right_excluded_value = (right < n-1) ? rightSum[right+1] : 0;

        return leftSum.back() - left_excluded_value - right_excluded_value;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */