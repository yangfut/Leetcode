class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int MOD = 1000000007;
        int n = nums.size();
        vector<int> nls(n,n), pls(n,-1);
        vector<long long> prefix(n,nums[0]);
        stack<int> st;
        // pls
        for(int i = 0; i < n; ++i){
            while(!st.empty() && nums[i] <= nums[st.top()]) st.pop();
            if(!st.empty()){
                pls[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();
        // nls
        for(int i = n-1; i >= 0; --i){
            while(!st.empty() && nums[i] <= nums[st.top()]) st.pop();
            if(!st.empty()){
                nls[i] = st.top();
            }
            st.push(i);
        }
        for(int i = 1; i < n; ++i){
            prefix[i] = prefix[i-1] + nums[i];
        }

        long long maxVal = 0;
        for(int i = 0; i < n; ++i){
            int r = nls[i];
            int l = pls[i];
            long long rangeSum = (l == -1) ? prefix[r-1] : prefix[r-1] - prefix[l];
            long long res = rangeSum * nums[i];
            maxVal = max(maxVal, res);
        }
        return maxVal % MOD;
    }
};