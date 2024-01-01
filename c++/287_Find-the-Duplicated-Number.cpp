class Solution {
public:
    int hashtable_solution(vector<int>& nums) {
        int n = nums.size();
        int mp[n];

        for(int i=0;i<n;i++) mp[i]=0;

        for(int ele:nums){
            if(mp[ele]==1) return ele;
            mp[ele]=1;
        }
        return -1;
    }
    
    int bruteforce_solution(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(nums[i]==nums[j]) return nums[i];
            }
        }
        return -1;
    }

    int binarysearch_recursion(vector<int>& nums, int low, int high) {
        //Pigeonhole principle
        if(low < high){
            int cnt = 0;
            int mid = low+(high-low)/2;
            for(int idx=0; idx<nums.size(); idx++){
                if(nums[idx]<=mid) cnt++;
            }

            if(cnt > mid) high = mid;
            else low = mid+1;

            return binarysearch_recursion(nums, low, high);
        }
        return low;
    }

    int floyed_algorithm_solution(vector<int>& nums) {
        //ref: https://medium.com/@simrangarg0501/finding-the-duplicate-number-using-floyds-tortoise-and-hare-algorithm-618ced80e98e
        int fast = 0, slow = 0;
        
        fast = nums[nums[fast]];
        slow = nums[slow];

        while(slow!=fast) {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        // Tortise: k steps = x + y + a * p
        // Hare:   2k steps = x + y + b * p
        // k = (b - a) * p
        // k + x = (b - a) * p + x -> if tortise moves another x steps, it stands on starting point
        // x = x -> if second tortise moves x steps, it stays on the same point
        int slow2 = 0;
        while(slow2!=slow) {
            slow2 = nums[slow2];
            slow = nums[slow];
        }
        return slow;
    }
    int findDuplicate(vector<int>& nums) {

        //
        // Solution#1 - Hash Table
        // TC:O(N+N), SC:O(N)
        // return hashtable_solution(nums);

        //
        // Solution#2 - Brute Force
        // TC:O(N^2), SC:O(1)
        // return bruteforce_solution(nums);

        //
        // Solution#3 - Binary Search
        // TC:(NlogN), SC:O(1)
        // return binarysearch_recursion(nums, 1, nums.size()-1);

        //
        // Solution#4 - Floyd’s Cycle Detection Algorithm
        // TC:O(N), SC:O(1)
        return floyed_algorithm_solution(nums);
    }
};