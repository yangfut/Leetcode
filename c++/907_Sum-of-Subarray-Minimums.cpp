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