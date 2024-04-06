class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int table[20001]={0};
        int offset=10000;
        int ans = 0;
        for(int ele:nums){
            table[ele+offset]++;
        }

        for(int idx=20000; idx>0; idx--){
            if(table[idx]==0) continue;

            k-=table[idx];
            if(k<=0){
                ans = idx;
                break;
            }
        }
        return ans-offset;
    }
};

class Solution {
public:
    // #1 Min Heap
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> pq; //min heap
        for(int ele:nums){
            pq.push(ele);
            if(pq.size()>k) pq.pop();
        }

        return pq.top();
    }
    // #2 Quick Select
    // int quickSelect(vector<int>& nums, int l, int r, int k){
    //     int ptr=l, pivot = nums[r];
    //     for(int i=l;i<r;++i){
    //         if(nums[i]<pivot){
    //             swap(nums[i], nums[ptr]);
    //             ++ptr;
    //         }
    //     }
    //     swap(nums[ptr], nums[r]);
    //     if(ptr>k) return quickSelect(nums, l, ptr-1, k);
    //     else if(ptr<k) return quickSelect(nums, ptr+1, r, k);
    //     return nums[ptr];
    // }
    // int findKthLargest(vector<int>& nums, int k) {
    //     k = nums.size()-k;
    //     return quickSelect(nums, 0, nums.size()-1, k);
    // }
};