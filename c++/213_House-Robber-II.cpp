class Solution {
private:
    int robTabulation(vector<int>& nums){
        // 1. Pick first one or Pick the last one
        // 2. Use tabulation in both scenarios

        int prev=0, n=nums.size(), maxValPickFirst=0, maxValPickLast=0;
        if(n==0) return 0;
        if(n==1) return nums[0];

        // Pick first
        for(int houseIdx=0; houseIdx<n-1;++houseIdx){
            int newVal = max(prev+nums[houseIdx], maxValPickFirst);
            prev = maxValPickFirst;
            maxValPickFirst = newVal;
        }

        prev=0;

        //Pick last
        for(int houseIdx=1; houseIdx<n;++houseIdx){
            int newVal = max(prev+nums[houseIdx], maxValPickLast);
            prev = maxValPickLast;
            maxValPickLast = newVal;
        }

        return max(maxValPickFirst, maxValPickLast);
    }

    int robMemoizationHelper(vector<int>& nums, vector<int>& memo, int idx, int end){
        if(idx<end) return 0;
        if(memo[idx]==-1){
            memo[idx] = std::max(robMemoizationHelper(nums, memo, idx-1, end), robMemoizationHelper(nums, memo, idx-2, end)+nums[idx]);
        }
        return memo[idx];
    }
    int robMemoization(vector<int>& nums){
        // 1. Get maxVal between n-1(Pick last) and n-2(Pick first)
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums.front();

        vector<int> memo1(n, -1);
        vector<int> memo2(n, -1);
        return max(robMemoizationHelper(nums, memo1, n-1, 1), robMemoizationHelper(nums, memo2, n-2, 0));
    }
public:
    // Clarfiy questions:
    // 1. What's the value range for nums[i]
    int rob(vector<int>& nums) {
        // Tabulation
        // return robTabulation(nums);

        // Memoization
        return robMemoization(nums);
    }
};