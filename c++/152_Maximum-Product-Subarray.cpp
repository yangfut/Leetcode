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

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>leftProduct(n);
        vector<int>rightProduct(n);

        leftProduct[0]=nums[0];
        for(int i=1; i<n; ++i){
            if(leftProduct[i-1]==0){
                // store the result excluding ZERO in the previous index
                leftProduct[i]=nums[i];

            }else{
                leftProduct[i]=leftProduct[i-1]*nums[i];
            }
            
        }

        rightProduct[n-1]=nums[n-1];
        for(int i=n-2; i>=0; --i){
            if(rightProduct[i+1]==0){
                // store the result exlucding ZERO in the next index
                rightProduct[i]=nums[i];
            }else{
                rightProduct[i]=rightProduct[i+1]*nums[i];
            }
        }

        int maxp;
        for(int i=0; i<n; ++i){
            int maxp_temp = max(leftProduct[i], rightProduct[i]);
            maxp = max(maxp, maxp_temp);
        }
        return maxp;
    }
};