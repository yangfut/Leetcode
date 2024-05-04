class Solution {
public:
    bool backtrack(const string& s, vector<vector<int>>& dp, int l, int idx){
        // l represents the number of remaining left paranthesis since right paranthesis would cancel them out
        // l should not be negative
        if(l < 0) return false;
        if(idx == s.length()) return l == 0;

        if(dp[l][idx] != -1) return dp[l][idx];

        bool isValid = false;
        switch(s[idx]){
            case '(':
                isValid |= backtrack(s, dp, l+1, idx+1);
                break;
            case ')':
                isValid |= backtrack(s, dp, l-1, idx+1);
                break;
            case '*':
                // empty string || left paranthesis || right paranthesis
                isValid = backtrack(s, dp, l, idx+1) || backtrack(s, dp, l+1, idx+1) || backtrack(s, dp, l-1, idx+1);
        }

        dp[l][idx] = isValid;
        return dp[l][idx];
    }

    bool backtrack_solution(string& s){
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return backtrack(s, dp, 0, 0);
    }
    
    bool traversal(string & s){
        int n = s.length(), count = 0;

        // (TAIL) Sum of the number of right paranthesis and asterisk should be greater or equal to the number of left paranthesis
        for(int idx = n-1; idx >=0; --idx){
            if(s[idx] == '(') --count;
            else ++count;

            if(count < 0) return false;
        }
        
        // (HEAD) Sum of the number of left paranthesis and asterisk should be greater or qual to the number of right paranthesis
        count = 0;
        for(int idx = 0; idx < n; ++idx){
            if(s[idx] == ')') --count;
            else ++count;

            if(count < 0) return false;
        }

        return true;
    }

    bool stack_solution(string& s){
        stack<int> left, star;
        int n = s.length();

        // store index of left paranthesis and star into stack
        // if meet right paranthesis remove element from left stack(first) or star stack(second)
        for(int idx = 0; idx < n; ++idx){
            
            switch(s[idx]){
                case '(':
                    left.push(idx);
                    break;
                case '*':
                    star.push(idx);
                    break;
                case ')':
                    if(!left.empty()) left.pop();
                    else if(!star.empty()) star.pop();
                    else return false;
                    break;
            }
        }

        // finally, check there's no left paranthesis after star by verify the index of stack
        while(!left.empty() && !star.empty()){
            if(left.top() > star.top()) return false;

            left.pop();
            star.pop();
        }

        return left.empty();
    }
    bool checkValidString(string s) {
        // 2D DP
        // return backtrack_solution(s);

        // Simple traversal
        // return traversal(s);

        // stack
        return stack_solution(s);
    }
};