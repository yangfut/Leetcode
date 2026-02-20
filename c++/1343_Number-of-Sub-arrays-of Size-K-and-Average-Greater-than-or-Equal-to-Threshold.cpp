class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int thr = k * threshold, n = arr.size();
        int curr = 0, ans = 0;
        for(int i = 0; i < n; ++i){
            curr += arr[i];
            if(i >= k) curr -= arr[i-k];
            if(i >= k-1){
                if(curr >= thr) ++ans; 
            }
        }
        return ans;
    }
};