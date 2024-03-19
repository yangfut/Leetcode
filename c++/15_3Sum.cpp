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

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 1. Count k from n-1 to 2
        // 2. nums[k]+nums[k-1]+nums[k-2]<0 stops!
        // 3. Use two pointers(i, j) starting from 0 and k-1 to find result
        
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int k=n-1;
        vector<vector<int>>ans_vec;
        while(k>1){
            if(nums[k]+nums[k-1]+nums[k-2]<0) break;
            int i=0, j=k-1;
            while(i<j){
                if(nums[i]+nums[j]==-nums[k]){
                    ans_vec.push_back({nums[i], nums[j], nums[k]});
                    //looking for different combinations
                    do{
                        ++i;
                    }while(i<j&&nums[i]==nums[i-1]);

                    do{
                        --j;
                    }while(i<j&&nums[j]==nums[j+1]);
                    continue;
                }
                
                if(nums[i]+nums[j]>-nums[k]) --j;
                else ++i;
            }

            do{
                --k;
            }while(k>1&&nums[k]==nums[k+1]);
        }

        return ans_vec;
    }
};