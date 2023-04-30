#include <map>

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<int, int>buckets;
        int st = 0, ed = 0;
        int size = nums.size();
        int bucketSize = valueDiff + 1;
        int bKey;
        int keyToRemove;
        while(ed < size){
            bKey = nums[ed] / (valueDiff + 1);
            if(nums[ed]<0) --bKey;
            if(buckets.find(bKey) == buckets.end()){
                if (buckets.find(bKey - 1) != buckets.end() && nums[ed] - buckets[bKey - 1] <= valueDiff) return true;
                if (buckets.find(bKey + 1) != buckets.end() && buckets[bKey + 1] - nums[ed] <= valueDiff) return true;
                buckets[bKey] = nums[ed];
            }else{
                return true;
            }

            ++ed;
            if((ed - st) > indexDiff){
                keyToRemove = nums[st] / (valueDiff + 1);
                if(nums[st]<0)--keyToRemove;
                buckets.erase(keyToRemove);
                ++st;
            }
        }
        return false;

    }
};