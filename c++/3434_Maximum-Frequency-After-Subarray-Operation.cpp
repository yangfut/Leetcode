class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int kcnt = count(nums.begin(), nums.end(), k);
        int best = 0;
        unordered_set<int> seen(nums.begin(), nums.end());
        for(int v : seen){
            if(v == k) continue;
            int curr = 0;
            for(int val : nums){
                if(val == v) ++curr;
                else if(val == k) --curr;

                best = max(best, curr);
                curr = max(curr, 0);
            }
        }
        return best + kcnt;
    }
};