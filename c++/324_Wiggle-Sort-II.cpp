class Solution {
public:
    void nth_element_sort_sol(vector<int>& nums) {
        if(nums.size()==1) return;
        
        int n=nums.size();
        //Sort vector into two groups
        nth_element(nums.begin(), nums.begin()+n/2, nums.end());
        int median=nums[n/2];

        //Rearrange the values that are equal to median
        int i=0, l=0, r=n-1;
        while(i<=r){
            if(nums[i]<median) swap(nums[l++], nums[i++]);
            else if(nums[i]>median) swap(nums[r--], nums[i]);
            else i++;
        }

        vector<int>temp(n);
        int ll=(n-1)/2; //half of two sub strings
        int rr=n-1;
        for(int idx=0;idx<n;idx++){
            if(idx%2==0&&ll>=0) temp[idx]=nums[ll--];
            else temp[idx]=nums[rr--];
        }
        nums=temp;
    }
    void sort_merge_sol(vector<int>& nums){
        sort(nums.begin(), nums.end());
        int l=0, r=nums.size()-1, m=l+(r-l)/2;
        vector<int>left_tmp(m-l+1);
        vector<int>right_tmp(r-m);

        for(int i=0;i<left_tmp.size();i++) left_tmp[i]=nums[i];
        for(int i=0;i<right_tmp.size();i++) right_tmp[i]=nums[m+i+1];

        for(int i=left_tmp.size()-1, j=right_tmp.size()-1, k=0;k<nums.size();k++){
            if(k%2==0) nums[k]=left_tmp[i--];
            else nums[k]=right_tmp[j--];
        }
    }
    void wiggleSort(vector<int>& nums) {
        //#1 Sort and Merge
        //return sort_merge_sol(nums);

        //#2 nth element sort
        return nth_element_sort_sol(nums);
    }
};