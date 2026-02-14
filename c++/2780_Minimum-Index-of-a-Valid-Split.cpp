class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int maj;
        int count = 0, n = nums.size();
        // Find majority via Boyer-Moore Majority Voting Algorithm
        for(int num : nums){
            if(!count) maj = num;
            count = (maj == num) ? count + 1 : count - 1;
        }

        // Find split point
        int majCount = 0, tempCount = 0;
        for(int num : nums) if(num == maj) ++majCount;

        for(int i = 0; i < n; ++i) {
            if(nums[i] == maj){
                ++tempCount;
                if(tempCount > (i+1)/2 && (majCount - tempCount) > (n-i-1)/2) return i;
            }
        }
        return -1;

    }
};

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int i = 0; i < n; ++i) ++freq[nums[i]];
        unordered_map<int, int> preFreq;
        for(int i = 0; i < n; ++i){
            int val = nums[i]; 
            ++preFreq[val];

            int preCount = preFreq[val];
            int postCount = freq[val] - preCount;
            if((preCount > (i+1)/2) && (postCount > (n-i-1)/2)) return i;
        }
        return -1;
    }
};