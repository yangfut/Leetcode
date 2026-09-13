class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,-1);
        stack<int>stack;
        int MOD=1000000007;
        int ans=0;

        for(int i=0;i<n;++i){
            //Previous Less Elements(PLE)->Monontic inceasing
            while(!stack.empty()&&arr[stack.top()]>arr[i]) stack.pop();

            if(!stack.empty()){
                int j=stack.top();
                dp[i] = dp[j] + arr[i]*(i-j);
            }else{
                dp[i] = arr[i]*(i+1);
            }
            stack.push(i);
            ans=(ans+dp[i])%MOD;
        }
        return ans;
    }
};

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1000000007;
        vector<vector<int>> dp(n, vector<int>(n,-1));
        for(int i = 0; i < n; ++i){
            int lmin = arr[i];
            for(int j = i; j < n; ++j){
                lmin = min(lmin, arr[j]);
                dp[i][j] = lmin;
            }
        }

        int sum = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i; j < n; ++j){
                sum += dp[i][j];
                sum %= mod;
            }
        }
        return sum;
    }
};

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9+7;
        long long sum = 0;
        vector<int> left(n,-1), right(n,n);
        stack<int> st;
        // next less element
        for(int i = n-1; i >= 0; --i){
            while(!st.empty() && arr[i] < arr[st.top()]) st.pop();
            if(!st.empty()){
                right[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();
        // previous less element
        for(int i = 0; i < n; ++i){
            while(!st.empty() && arr[i] <= arr[st.top()]) st.pop();
            if(!st.empty()){
                left[i] = st.top();
            }
            st.push(i);
        }

        for(int i = 0; i < n; ++i){
            int ldist = i - left[i];
            int rdist = right[i] - i;
            sum = (sum + ((long long)arr[i] * ldist * rdist)) % mod;
        }
        return sum;
    }
};