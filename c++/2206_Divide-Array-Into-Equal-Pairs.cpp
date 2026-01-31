class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int idx = 1; idx < nums.size(); idx+=2){
            if(nums[idx-1] != nums[idx]) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int m = nums.size(), n = m / 2;
        unordered_map<int,int> freq;
        for(int val : nums) ++freq[val];
        for(auto& p : freq){
            if(p.second % 2 != 0) return false;
        }
        return true;
    }
};