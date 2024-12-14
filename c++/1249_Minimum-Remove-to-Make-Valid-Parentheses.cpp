class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        int valid = 0;
        for(char &c : s){
            if(c == ')' && valid <= 0) continue;
            if(c == '(') ++valid;
            if(c == ')') --valid;

            st.push(c);
        }

        string res;
        while(!st.empty()){
            if(valid > 0 && st.top() == '('){
                st.pop();
                --valid;
                continue;
            }

            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // mark invalid right parentheses
        stack<int> st;
        vector<char> res(s.begin(), s.end());
        for(int i = 0; i < res.size(); ++i){
            if(res[i] == '(') st.push(i);
            else if(res[i] == ')' && !st.empty()) st.pop();
            else if(res[i] == ')') res[i] = '*'; 
        }
        // mark invalid left parentheses
        while(!st.empty()){
            res[st.top()] = '*';
            st.pop();
        }

        // replace all invalid parentheses
        string ans;
        for(char &c : res){
            if(c == '*') continue;
            ans += c;
        }

        return ans;
    }
};