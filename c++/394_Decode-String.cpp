class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string output;
        int n = s.length();
        for(int i = 0; i < n; ++i){
            if(s[i] != ']'){
                st.push(s[i]);
            }else{
                string subStr;
                while(!st.empty() && st.top() != '['){
                    subStr += st.top();
                    st.pop();
                }
                st.pop();
                reverse(subStr.begin(), subStr.end());
                int num = 0;
                int mul = 1;
                while(!st.empty() && isdigit(st.top())){
                    num += (st.top() - '0') * mul;
                    mul *= 10;
                    st.pop();
                }

                string tempStr;
                for(int j = 0; j < num; ++j) tempStr += subStr;
                for(char& c : tempStr) st.push(c); 
            }
        }

        while(!st.empty()){
            output += st.top();
            st.pop();
        }
        reverse(output.begin(), output.end());
        return output;
    }
};

// Two stack solution - for nested strucure, think about multiple stack to resolve it
class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        int currNum = 0;
        string currStr = "";
        
        for(char& c : s){
            if(isdigit(c)){
                currNum = (currNum * 10) + (c - '0');
            }else if(c == '['){
                numStack.push(currNum);
                strStack.push(currStr);
                currNum = 0;
                currStr = "";
            }else if(c == ']'){
                int repeat = numStack.top(); numStack.pop();
                string prev = strStack.top(); strStack.pop();
                string tempStr = "";
                for(int i = 0; i < repeat; ++i) tempStr += currStr;
                currStr = prev + tempStr;
            }else{
                currStr += c;
            }
        }
        return currStr;
    }
};