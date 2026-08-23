class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Two scenarios: (1) wrap (2) non-wrap
        // For (2), find maximum subarray via Kadanes's algorithm
        // For (1), findm minimum subarray via Kadanes's algorithm. Since maximum subarray is wrapped, so minimum array must be unwrapped
        int n = nums.size();
        int currMax = 0, currMin = 0;
        int globalMax = INT_MIN, globalMin = INT_MAX;

        int totalSum = 0;
        for(int val : nums) totalSum += val;
        for(int val : nums){

            // Maximum Kadane's algorithm
            currMax = max(currMax, 0) + val;
            globalMax = max(globalMax, currMax);

            // Minimum Kadane's algorithm
            currMin = min(0, currMin) + val;
            globalMin = min(globalMin, currMin);
        }

        if(globalMax < 0) return globalMax;

        // if all negative, totalSum - globalMin must be zero
        return max(globalMax, totalSum - globalMin);
    }
};

// Greedy (Kadane's algorithm)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Consider wrap and non-wrap case
        int loMax = 0, glMax = INT_MIN, loMin = 0, glMin = INT_MAX;
        int sum = 0;
        for(int ele : nums){
            sum += ele;

            loMax = max(loMax, 0) + ele;
            loMin = min(loMin, 0) + ele;

            glMax = max(loMax, glMax);
            glMin = min(loMin, glMin);
        }

        if(sum - glMin == 0) return glMax;
        return max(glMax, sum - glMin);
    }
};

// Sliding Window in size of n
// TC: O(N), SC:O(N)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix (2*n+1, 0);
        for(int i = 0; i < 2*n; ++i){
            prefix[i+1] = prefix[i] + nums[i % n];
        }

        deque<int> deq;
        deq.push_back(0);
        int res = INT_MIN;
        
        for(int i = 1; i <= 2*n; ++i){
            // expired starting point
            while(!deq.empty() && i - deq.front() > n) deq.pop_front();
            res = max(res, prefix[i] - prefix[deq.front()]);
            // Find minimum sum
            while(!deq.empty() && prefix[i] <= prefix[deq.back()]) deq.pop_back();
            deq.push_back(i);
        }
        return res;
    }
};

// Brute force with prefix sums
// TC: O(N^2), SC: O(M)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(2*n+1, 0);
        for(int i = 0; i < 2*n; ++i){
            prefix[i+1] = prefix[i] + nums[i%n];
        }
        
        int res = INT_MIN;
        for(int i = 0; i <= 2*n; ++i){
            for(int j = i+1; j <= 2*n && j-i <= n; ++j){
                res = max(res, prefix[j] - prefix[i]);
            }
        }
        return res;
    }
};