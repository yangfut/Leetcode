class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(int i=0, n=nums.size();i<=n-3;i++){
            //Math
            if(nums[i]+nums[i+1]+nums[i+2]>0) break;
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[n-1]+nums[n-2]<0) continue;
            int l=i+1;
            int r=n-1;
            while(l<r){
                int sum=nums[l]+nums[r]+nums[i];
                if(sum==0){
                    ans.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    do{
                        l++;
                    }while(l<n-1&&nums[l]==nums[l-1]);
                }
                else if(sum>0) r--;
                else l++;
            }
        }
        return ans;
    }
};