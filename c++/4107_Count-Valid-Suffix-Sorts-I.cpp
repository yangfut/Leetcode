class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size(), cnt = 0;
        for(int i = 0; i < n; ++i){
            vector<int> res = nums;
            sort(res.begin() + i, res.end(), greater<int>());
            if(res == target) ++cnt;
        }
        return cnt;
    }
};

class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        unordered_map<int,int>cnt;
        for(int x : target) ++cnt[x];
        for(int x : nums) --cnt[x];
        for(auto& [val,c] : cnt) if(c != 0) return 0;

        // p: length of longest common prefix
        // edge case: p is n when all elements are same
        int p = 0;
        while(p < n && nums[p] == target[p]) ++p;

        // s: first index with non-increasing array
        int s = n-1;
        while(s > 0 && target[s-1] >= target[s]) --s;
        p = min(p,n-1);
        return max(p-s+1,0);
    }
};