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

class Solution {
public:
    int numDecodings(string s) {

        // Tabulation
        set<string> validCode;
        int n=s.length();
        vector<int> dp(n, 0);
        for(int code=1; code<=26;++code) validCode.insert(to_string(code));

        for(int idx=0; idx<n; ++idx){
            string c(1,s[idx]);

            if(idx==0){
                dp[idx] = validCode.count(c);
            }else if(idx==1){
                dp[idx] = validCode.count(c) ? dp[idx-1] : 0;
                dp[idx] += validCode.count(s.substr(idx-1,2)) ? 1 : 0;
            }else{
                dp[idx] = validCode.count(c) ? dp[idx-1] : 0;
                dp[idx] += validCode.count(s.substr(idx-1,2)) ? dp[idx-2] : 0;
            }

        }
        return dp.back();
    }
};

class Solution {
public:
    int numDecodings(string s) {

        // Tabulation
        int n=s.length();
        vector<int> dp(n, 0);
        int lower = '1'*10 + '0';
        int upper = '2'*10 + '6';
        for(int idx=0; idx<n; ++idx){
            
            // Check single digit
            if(s[idx]!='0'){
                dp[idx] = (idx>0) ? dp[idx-1] : 1;
            }

            // Check double digits
            if(idx>0){
                int twoDigits = s[idx-1]*10+s[idx];
                if(twoDigits >= lower && twoDigits <= upper){
                    dp[idx] += (idx>1) ? dp[idx-2] : 1;
                }
            }
        }
        return dp.back();
    }
};