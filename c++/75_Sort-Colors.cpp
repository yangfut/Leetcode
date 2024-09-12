#include <vector>

class Solution {
public:
    void counting_sort(vector<int>& nums) {
        int bucket[3] = {0};
        for(int ele:nums){
            bucket[ele]++;
        }

        int j=0;
        for(int idx=0;idx<nums.size(); idx++){
            while(bucket[j]==0) j++;
            nums[idx] = j;
            bucket[j]--;
        }
    }

    void merge_sort_merge(vector<int>&nums, int low, int mid, int high) {
        int llen = mid-low+1;
        int rlen = high-mid;
        int temp_left[llen], temp_right[rlen];

        //Copy element to temp array
        for(int idx=0; idx<llen; idx++) temp_left[idx] = nums[low+idx];
        for(int idx=0; idx<rlen; idx++) temp_right[idx] = nums[mid+idx+1];

        //Merge
        for(int i=0, j=0, k=low; k<=high; k++){
            if(i<llen && (j>=rlen || temp_left[i]<temp_right[j])){
                nums[k] = temp_left[i];
                i++;
            }else{
                nums[k] = temp_right[j];
                j++;
            }
        }
    }

    void merge_sort_recursion(vector<int>&nums, int low, int high){
        if(low < high){
            int mid = low+(high-low)/2;
            merge_sort_recursion(nums, low, mid);
            merge_sort_recursion(nums, mid+1, high);

            merge_sort_merge(nums, low, mid, high);
        }
    }
    void two_pointers(vector<int>& nums) {
        int zero_idx = 0, two_idx = nums.size()-1;
        int idx = 0;

        while(idx <= two_idx) {
            switch(nums[idx]){
                case 0:
                    swap(nums[idx], nums[zero_idx]);
                    zero_idx++;
                case 1:
                    idx++;
                    break;
                case 2:
                    swap(nums[idx], nums[two_idx]);
                    two_idx--;
                    break;
            }
        }
    }
    
    void sortColors(vector<int>& nums) {
        
        //
        // Solution#1 - Counting Sort
        // TC:O(N+K), SC:O(K)
        //counting_sort(nums);
        
        //
        // Solution#2 - Merge Sort
        // TC:O(NlogN), SC:O(N)
        //merge_sort_recursion(nums, 0, nums.size()-1);

        //
        // Solution#3 - Two Pointers
        // TC:O(N), SC:O(1)
        two_pointers(nums);
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};
        for(int num : nums) ++count[num];
        for(int i = 0; i < count[0]; ++i) nums[i] = 0;
        for(int i = count[0]; i < count[0]+count[1]; ++i) nums[i] = 1;
        for(int i = count[0]+count[1]; i < nums.size(); ++i) nums[i] = 2;
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] == 0){
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
        
        for(int i = ptr; i < n; ++i){
            if(nums[i] == 1){
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
    }
};