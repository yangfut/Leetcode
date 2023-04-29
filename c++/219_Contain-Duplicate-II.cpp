#include <map>
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
	int st = 0, ed = 0;
	int size = nums.size();
    unordered_map<int, int>mp;


	while(ed < size){
	
        if(mp.find(nums[ed]) == mp.end()){
            mp.insert({nums[ed], 1});
        }else{
            return true;
        }

        ++ed;
        if((ed - st) > k){
            mp.erase(nums[st]);
            ++st;
        }
    }
    return false;
    }
};
