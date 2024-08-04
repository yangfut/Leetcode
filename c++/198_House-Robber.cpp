class Solution {
private:
    int tabulation(vector<int>& nums){
        int prevMax=0, n=nums.size();
        vector<int>tab(n, 0);
        for(int houseIdx=0; houseIdx<n; ++houseIdx){
            if(houseIdx>=2) prevMax=max(prevMax, tab[houseIdx-2]);
            tab[houseIdx] = nums[houseIdx] + prevMax;
        }
        return (n>1)?max(tab.back(), tab[n-2]):tab.back();
    }

    int _recursion(vector<int>& nums, vector<int>& memo, int idx){
        if(idx<0) return 0;
        if(memo[idx]==-1){
            memo[idx] = max(_recursion(nums, memo, idx-1), _recursion(nums, memo, idx-2)+nums[idx]);
        }
        return memo[idx];
    }
    int memoization(vector<int>& nums){
        int n=nums.size();
        vector<int>memo(n, -1);

        return _recursion(nums, memo, n-1);
    }
public:
    int rob(vector<int>& nums) {
        // #1 Tabulation
        // return tabulation(nums);

        // #2 Memoization
        return memoization(nums);
    }
};

class Solution {
public:
    int _recursion(vector<int>& nums, vector<int>& memo, int idx){
        // termination
        if(idx < 0) return 0;

        // memoization
        if(memo[idx] != -1) return memo[idx];

        // pick
        int take = _recursion(nums, memo, idx-2) + nums[idx];

        // not pick
        int nottake = _recursion(nums, memo, idx-1);
        return memo[idx] = max(take, nottake);
    }
    int rob(vector<int>& nums) {
        // #1 Memoization - TopDown
        // int n = nums.size();
        // vector<int> memo(n, -1);
        // return _recursion(nums, memo, n-1);

        // #2 Tabulation - BottomUp
        int maxv = 0, n = nums.size();
        vector<int> acc(n, -1);
        for(int idx = 0; idx < n; ++idx){
            int prev = (idx-2 >= 0) ? acc[idx-2] : 0;
            if(prev+nums[idx] > maxv){
                acc[idx] = prev+nums[idx];
                maxv = acc[idx];
            }else{
                acc[idx] = maxv;
            }
        }
        return maxv;
        
    }
};