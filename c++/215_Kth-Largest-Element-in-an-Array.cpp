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