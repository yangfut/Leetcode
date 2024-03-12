class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]=i;
        }

        for(int i=0;i<nums.size();i++){
            if(map.count(target-nums[i])) {
                if(i==map[target-nums[i]]) continue;
                return vector<int>{map[target-nums[i]], i};
            }
        }
        return vector<int>{-1};
    }
};