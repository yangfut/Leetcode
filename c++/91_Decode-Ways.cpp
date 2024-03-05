class Solution {
public:
    //dp[i+1] = dp[i] (valid single digit) + d[i-1](valid double digits)
    int numDecodings(string s) {
        vector<int>dp(s.size()+1, 0);
        dp[0]=1;

        for(int i=0;i<s.size();i++){
            //Check single digit
            if(s[i]!='0'){
                dp[i+1]+=dp[i];
            }

            //Check double digits
            if(i>0){
                int double_digits = (s[i-1]-'0')*10+s[i];
                //double_digits >= "10" && double_digits <= "26"
                if(double_digits>=58&&double_digits<=74){
                    dp[i+1]+=dp[i-1];
                }
            }
        }
        return dp.back();
    }
};