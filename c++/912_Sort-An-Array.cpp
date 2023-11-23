class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //Approach 1
        //ref: https://www.youtube.com/watch?v=0jDiBM68NGU
        //quickSort(nums,0,nums.size()-1);

        //Approach 2
        //ref: https://www.youtube.com/watch?v=LeWuki7AQLo
        merge_sort(nums);
        return nums;
    }
    void merge_sort(vector<int>& nums){
        merge_sort_recursion(nums, 0, nums.size()-1);
    }
    void merge_sort_recursion(vector<int>& nums, int low, int high){
        if(low < high){
            int mid = (low+high)/2;
            merge_sort_recursion(nums, low, mid);
            merge_sort_recursion(nums, mid+1, high);
            merge_sort_merge(nums, low, mid, high);
        }
    }
    
    void merge_sort_merge(vector<int>& nums, int low, int mid, int high){
        int llen = mid-low +1;
        int rlen = high-mid;
        int temp_left_arr[llen];
        int temp_right_arr[rlen];

        for(int i = 0; i < llen; ++i){
            temp_left_arr[i] = nums[low+i];
        }

        for(int i = 0; i < rlen; ++i){
            temp_right_arr[i] = nums[mid+1+i];
        }

        for(int i = 0, j = 0, k = low; k <= high; ++k){
            if(i <  llen && (j >= rlen || temp_left_arr[i] <= temp_right_arr[j])){
                nums[k] = temp_left_arr[i];
                ++i;
            }else{
                nums[k] = temp_right_arr[j];
                ++j;
            }
        }
    }
    
    void quickSort(vector<int>& nums,int low,int high){
        
        if(low>=high){
            return;
        }
        
        int pivot=high;
        
        int mid=partition(nums,low,high,pivot);
        // cout<<"idx: "<<mid<<" "<<nums[mid];
        quickSort(nums,low,mid-1);
        quickSort(nums,mid+1,high);
    }
    int partition(vector<int>& nums,int low,int high,int tar){
        int i=low;
        int j=low;
        
        while(i<=high){
            if(nums[i]<=nums[tar]){
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                j++;
            }
            i++;
        }
        return j-1;
    }
};