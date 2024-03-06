class Solution {
public:
    void backtrack_sol(int left, int right, string s, vector<string>&result){
        
        if(right==0){
            result.emplace_back(s.begin(), s.end());
            return;
        }

        if(left>0){
            --left;
            s.push_back('(');
            backtrack_sol(left, right, s, result);
            s.pop_back();
            ++left;
        }

        if(left<right){
            --right;
            s.push_back(')');
            backtrack_sol(left, right, s, result);
            s.pop_back();
            right++;
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string>result;
        int left=n, right=n;
        backtrack_sol(left, right, "", result);
        return result;
    }
};