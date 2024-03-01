class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int max_product, n=nums.size();
        vector<int>lproduct(nums.size(), nums[0]);
        vector<int>rproduct(nums.size(), nums[n-1]);

        for(int i=1;i<n-1;i++){
            if(lproduct[i-1]==0) lproduct[i]=nums[i];
            else lproduct[i]=nums[i]*lproduct[i-1];
        }

        for(int i=n-2;i>=0;i--){
            if(rproduct[i+1]==0) rproduct[i]=nums[i];
            else rproduct[i]=nums[i]*rproduct[i+1];
        }

        for(int i=0;i<n;i++){
            int temp=max(lproduct[i], rproduct[i]);
            max_product=max(max_product, temp);
        }
        return max_product;
        
    }
};