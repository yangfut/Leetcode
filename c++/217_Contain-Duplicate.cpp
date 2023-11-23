class Solution {
public:
    /*
    // Approach 1: Map
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int>mp;
        bool isDuplicated = false;
        for(int ele : nums){
            if(mp.find(ele) == mp.end()) {
                mp.insert(pair<int, int>(ele, 0));
            }else{
                isDuplicated = true;
            }
        }
        return isDuplicated;
    }
    */
    
    // Approach 2: Sort
    void merge_sort_recursion(vector<int>& nums, int low, int high){
        if(low < high){
            int mid = (low + high)/2;
            merge_sort_recursion(nums, low, mid);
            merge_sort_recursion(nums, mid+1, high);

            merge_sort_merge(nums, low, mid, high);
        }
    }
    void merge_sort_merge(vector<int>& nums, int low, int mid, int high){
        int llen = mid-low+1;
        int rlen = high-mid;
        int temp_left[llen], temp_right[rlen];
        for(int i = 0; i < llen; ++i){
            temp_left[i] = nums[low+i];
        }
        for(int i = 0; i < rlen; ++i){
            temp_right[i] = nums[mid+1+i];
        }

        for(int i = 0, j = 0, k = low; k <= high; ++k){
            if(i<llen && (j >= rlen || temp_left[i] < temp_right[j])){
                nums[k] = temp_left[i];
                ++i;
            }else{
                nums[k] = temp_right[j];
                ++j;
            }
        }
    }
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==1) return false;

        merge_sort_recursion(nums, 0, nums.size()-1);
        int prev = nums[0];
        for(int idx=1; idx < nums.size(); ++idx){
            if(prev == nums[idx]) return true;
            prev = nums[idx];
        }
        return false;
    }
};