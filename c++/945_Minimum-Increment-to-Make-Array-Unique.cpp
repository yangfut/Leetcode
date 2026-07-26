// Hash Table
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ops = 0;
        map<int,int> freq;
        for(int num : nums) ++freq[num];
        for(auto p : freq){
            if(p.second == 1) continue;
            freq[p.first + 1] += (p.second - 1);
            ops += p.second - 1;
        }
        return ops;
    }
};

// Sort
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0, ops = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == nums[i-1]) {
                ++cnt;
            }
            else{
                int h = nums[i] - nums[i-1] - 1;
                cnt = (h > cnt) ? 0 : cnt - h;
            }
            ops += cnt;
        }
        return ops;
    }
};