class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n,1), cnt(n,1);
        for(int i = 0; i < n; ++i){
            for(int j = i-1; j >= 0; --j){
                if(nums[i] > nums[j]){
                    // Update with longest sequence
                    if(len[j] + 1 > len[i]){
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }else if(len[i] == (len[j] + 1)){
                        cnt[i] += cnt[j];
                    }
                }
            }
        }
        int maxv = INT_MIN, maxc = 0;
        for(int i = 0; i < n; ++i){
            if(len[i] > maxv){
                maxc = cnt[i];
                maxv = len[i];
            }else if(len[i] == maxv){
                maxc += cnt[i];
            }
        }
        return maxc;
    }
};