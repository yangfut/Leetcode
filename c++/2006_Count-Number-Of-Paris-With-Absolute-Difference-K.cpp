#include <map>
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        /* 
        //#1 Brut-force 
        int ans = 0;
        int diff;
        for(int idx = 0; idx < nums.size()-1; idx++){
            for(int child_idx = idx+1; child_idx < nums.size(); child_idx++){
                diff = nums[idx] - nums[child_idx];
                if(diff >= 0){
                    if(k-diff == 0) ans++;
                }else{
                    if(diff+k == 0) ans++;
                }
            }
        }
        return ans;
        */
        //#2 Hashing
        int cnt=0;
        unordered_map<int, int>mp;

        for(int ele : nums){
            if(mp.find(ele+k) != mp.end())cnt+=mp[ele+k];
            if(mp.find(ele-k) != mp.end())cnt+=mp[ele-k];
            mp[ele]++;
        }
        return cnt;
    }
};