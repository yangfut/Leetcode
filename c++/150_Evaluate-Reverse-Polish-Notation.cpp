#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int num1, num2;
        for(string token:tokens){
            if(token=="+"||token=="-"||token=="*"||token=="/") {
                num2=st.top(); st.pop();
                num1=st.top(); st.pop();
                
                if(token=="+") st.push(num1+num2);
                else if(token=="-") st.push(num1-num2);
                else if(token=="*") st.push(num1*num2);
                else if(token=="/") st.push(num1/num2);
            }else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};