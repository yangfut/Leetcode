class Solution {
public:
    void merge_with_buff(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>temp(m);
        for(int i=0;i<m;i++)temp[i]=nums1[i];
        for(int i=0, j=0, k=0;k<(m+n);k++){
            if(i<m&&(j>=n||temp[i]<nums2[j])) nums1[k]=temp[i++];
            else nums1[k]=nums2[j++];
        }
    }
    
    void backward_merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(j>=0){
            if(i>=0&&(nums1[i]>nums2[j])){
                nums1[k]=nums1[i--];
            }else{
                nums1[k]=nums2[j--];
            }
            k--;
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //#1 merge with buffer
        //merge_with_buff(nums1, m, nums2, n);

        //#2 backward merge
        backward_merge(nums1, m, nums2, n);
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int lSize = m ? m : 1;
        int rSize = n ? n : 1;
        int left[lSize];
        int right[rSize];
        for(int i = 0; i < m; ++i) left[i] = nums1[i];
        for(int i = 0; i < n; ++i) right[i] = nums2[i];
        
        for(int i = 0, j = 0, k = 0; i < (m+n); ++i){
            
            if(j == m){
                nums1[i] = right[k++];
            }else if(k == n){
                nums1[i] = left[j++];
            }else if(left[j] <= right[k]){
                nums1[i] = left[j++];
            }else{
                nums1[i] = right[k++];
            }
        }
    }
};