// https://leetcode.com/problems/subarray-sum-equals-k/description/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // presum algorithm + hash map
        unordered_map<int,int> preSumCount{{0,1}};
        int currSum = 0, match = 0;
        for(int num : nums){
            currSum += num;
            if(preSumCount.count(currSum - k)){
                match += preSumCount[currSum - k];
            }

            ++preSumCount[currSum];
        }
        return match;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Algorithm: Prefix Sum with Hash Map
        // Store the frequency of prefix sums
        unordered_map<int, int> prefixSumCount{{0, 1}};
        int currentSum = 0;
        int count = 0;

        for (int &num : nums) {
            currentSum += num;

            // Check if there is a previous prefix sum that makes up the target sum 'k'
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[currentSum - k];
            }

            // Record the current prefix sum
            prefixSumCount[currentSum]++;
        }

        return count;
    }
};

