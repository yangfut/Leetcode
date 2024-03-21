class Solution {
public:
    double binary_search_in_two_arrays(vector<int>& nums1, vector<int>& nums2, int median){
        int l1, l2, r1, r2, idx;
        l2=0, r2=nums2.size();
        while(l2<r2){
            int m2=l2+(r2-l2)/2;
            l1=0, r1=nums1.size();
            while(l1<r1){
                int m1=l1+(r1-l1)/2;
                if(nums1[m1]<=nums2[m2]) l1=m1+1;
                else r1=m1;
            }

            idx=m2+l1;
            if(idx==median) return (double) nums2[m2];
            else if (idx>median) r2=m2;
            else l2=m2+1;
        }
        // Not found in nums2, so found nums1
        // Since in upper bound search, so the total index of l2 value is greater than median

        l1=0, r1=nums1.size();
        int temp=l2;
        while(l1<r1){
            int m1=l1+(r1-l1)/2;
            l2=0, r2=temp;
            while(l2<r2){
                int m2=l2+(r2-l2)/2;
                if(nums2[m2]<=nums1[m1]) l2=m2+1;
                else r2=m2;
            }

            idx=m1+l2;
            if(idx==median) return (double) nums1[m1];
            else if(idx>median) r1=m1;
            else l1=m1+1;
        }
        return (double) nums1[l1];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int count = nums1.size() + nums2.size();
        int median = count/2;
        if(count%2==1) return binary_search_in_two_arrays(nums1, nums2, median);
        else return (binary_search_in_two_arrays(nums1, nums2, median)+binary_search_in_two_arrays(nums1, nums2, median-1))/2;
    }
};