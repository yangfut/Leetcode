class Solution {
public:
    int dfs(vector<int>&nums, int prev, int idx, vector<int>&cache){
        // Boundary condition
        if(idx==nums.size()) return 0;

        // Check if optimal solution exists
        if(cache[prev]!=0) return cache[prev];

        // with
        int with=0;
        if(nums[idx]>nums[prev]){
            with=(cache[idx]!=0)? cache[idx]:1+dfs(nums,idx,idx+1,cache);
            cache[idx]=with;
        }
        // without
        int without=dfs(nums,prev,idx+1,cache);

        // Store optimal solution to cache
        cache[prev]=max(with,without);
        return cache[prev];
    }
    int dfs_solution(vector<int>& nums){
        
        // TC:O(N^2)
        // SC:O(N)
        int ans=0;
        vector<int> cache(nums.size(), 0);
        for(int i=0;i<nums.size();i++){
            if(cache[i]==0) cache[i] = dfs(nums, i, i+1, cache);
            if(cache[i]>ans) ans=cache[i];
        }
        return 1+ans;
    }

    int dp_solution(vector<int>&nums){
        vector<int>dp(nums.size(),1);
        int ans=0;
        for(int i=1; i<nums.size();i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]) dp[i] = max(dp[i], dp[j]+1);
            }
        }
        for(int ele:dp) ans=(ele>ans)?ele:ans;
        return ans;
    }

    int stl_based_solution(vector<int>&nums){
        if(nums.size()==0) return 0;
        // If incoming element is greater than the last element of S, we extend S
        // Insert and replace the smallest element that is not smaller than the incoming element
        vector<int>vec;
        vec.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>vec.back()) vec.push_back(nums[i]);
            else{
                int idx=lower_bound(vec.begin(), vec.end(), nums[i])-vec.begin();
                nums[idx]=nums[i];
            }
        }
        return vec.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        
        // #1 DFS + Memorization
        // TC:O(N^2), SC:O(N)
        // return dfs_solution(nums);
        
        // #2 Dynamic Programming
        // TC:O(N^2) SC:O(N)
        return dp_solution(nums);

        // #3 Genius Solution
        // TC:O(NlogN) SC:O(N)
        return stl_based_solution(nums);

    }
};

class Solution {
public:
    int dfsHelper(const vector<int>& nums, vector<int>& cache, int currIdx, int nextIdx){
        if(nextIdx == nums.size()) return 1;

        int seqLen = 0;
        for(int idx = nextIdx; idx < nums.size(); ++idx){
            // monotonic increasing
            if(nums[currIdx] >= nums[idx]) continue;
            if(cache[idx] == -1) cache[idx] = dfsHelper(nums, cache, idx, idx+1);
            seqLen = max(seqLen, cache[idx]);
        }

        cache[currIdx] = seqLen + 1;
        return cache[currIdx];
    }
    // Create decision tree for every iteration
    // Use cache to store the optimal solution(LIS)
    // To get optimal solution, must calculate all the sub sequences 
    int dfs_cache_sol(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;

        vector<int>cache(n, -1);
        int maxv = 0;

        for(int currIdx = 0; currIdx < n; ++currIdx){
            if(cache[currIdx] == -1) cache[currIdx] = dfsHelper(nums, cache, currIdx, currIdx+1);
            maxv = max(maxv, cache[currIdx]);
        }
        return maxv;
    }

    // Use tabulation method to count LIS from last element, which must be 1
    // Each current idx must look forward to find the max value in its subseq
    int tabulation_solution(vector<int>& nums){
        int n = nums.size();
        if(n == 1) return 1;

        vector<int> dp(n, 1);
        int LIS = 0;
        for(int l = n-2; l >=0; --l){
            for(int r = l+1; r < n; ++r){
                if(nums[l] >= nums[r]) continue;
                dp[l] = max(dp[l], dp[r]+1);
            }
        }

        for(int& length : dp) LIS = max(LIS, length);
        return LIS;
    }

    int binarySearch_solution(vector<int>& nums) {
        // Edge case
        if(nums.size()==1) return 1;
        int n = nums.size();
        vector<int> subSeq;
        subSeq.push_back(nums[0]);

        for(int i=1; i<n; ++i){
            if(subSeq.back() < nums[i]) subSeq.push_back(nums[i]);
            else{
                int idx = upper_bound(subSeq.begin(), subSeq.end(), nums[i]) - subSeq.begin();
                if(idx == 0 || subSeq[idx-1] != nums[i]){
                    subSeq[idx] = nums[i];
                }
            }
        }
        return subSeq.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        // 1. DFS with caching
        // TC: O(N^2), SC:O(N)
        // return dfs_cache_sol(nums);

        // 2. Dynamic Programming with Tabulation
        // TC: O(N^2), SC:O(N)
        // return tabulation_solution(nums);

        // 3. Binary Search
        // TC:O(NlogN), SC:O(N)
        return binarySearch_solution(nums);
    }
};