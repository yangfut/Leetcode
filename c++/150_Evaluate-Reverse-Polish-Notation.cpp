#include <stack>
#include <unordered_set>
#include <string>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>stack;
        unordered_set<string>operators = {"+", "-", "*", "/"};
        for(string s:tokens){
            if(operators.count(s)){
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                if(s=="+")
                    stack.push(a+b);
                else if(s=="-")
                    stack.push(a-b);
                else if(s=="*")
                    stack.push(a*b);
                else if(s=="/"){
                    if(b==0){
                        // Handle division by zero error
                        throw runtime_error("Division by zero");
                    }
                    stack.push(a/b);
                }
            }else{
                stack.push(stoi(s));
            }
        }
        return stack.top();
    }
};