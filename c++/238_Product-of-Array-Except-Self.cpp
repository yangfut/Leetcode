class Solution {
public:
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> ans(n, 0);
    //     vector<int> prefix(n, 1);
    //     vector<int> suffix(n, 1);

    //     prefix[0] = nums[0];
    //     for(int idx=1; idx<n; idx++){
    //         prefix[idx] = prefix[idx-1] * nums[idx];
    //     }

    //     suffix[n-1] = nums[n-1];
    //     for(int idx=n-2; idx>0; idx--){
    //         suffix[idx] = suffix[idx+1] * nums[idx];
    //     }

    //     for(int idx=0; idx<n; idx++){
    //         if(idx-1<0){
    //             ans[idx] = suffix[idx+1];
    //         }else if(idx+1>n-1){
    //             ans[idx] = prefix[idx-1];
    //         }else{
    //             ans[idx] = prefix[idx-1] * suffix[idx+1];
    //         }
    //     }

    //     return ans;
    // }
    
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n, 1);
        int cur=1;

        for(int i=0;i<n;++i){
            res[i] = cur;
            cur *= nums[i]; //left product
        }
        cur=1;
        for(int i=n-1;i>=0;--i){
            res[i] *= cur;
            cur *= nums[i]; //right product;
        }
        return res;
    }
};