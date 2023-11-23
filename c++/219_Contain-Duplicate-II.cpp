#include <map>
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(int idx = 0; idx < nums.size(); ++idx){
            if(mp.find(nums[idx]) == mp.end()){
                mp.insert(pair<int, int>(nums[idx], 0));
            }else{
                return true;
            }

            if(idx >= k){
                mp.erase(nums[idx-k]);
            }
        }
        return false;
    }
};
