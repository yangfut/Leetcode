
// Poos solution
// 1. Hard to prove correctness
// 2. Overly complex
class Solution {
public:
    bool check(vector<int>& nums) {
        int minIdx = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            if(nums[i] < nums[minIdx]) minIdx = i;
        }
        int prevIdx = minIdx, currIdx = (minIdx-1+n)%n;
        while(nums[currIdx] <= nums[prevIdx] && currIdx != minIdx){
            prevIdx = currIdx;
            currIdx = (currIdx-1+n)%n;
        }
        minIdx = prevIdx;

        int start = minIdx;
        currIdx = (minIdx+1)%n;
        while(currIdx != start){
            if(nums[currIdx] < nums[prevIdx]) return false;
            prevIdx = currIdx;
            currIdx = (currIdx+1) % n;
        }
        return true;
    }
};

// Optimal solution
class Solution {
public:
    bool check(vector<int>& nums) {
        // Count drops
        int n = nums.size(), drops = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] > nums[(i+1)%n]) ++drops;
        }

        return drops <= 1;
    }
};