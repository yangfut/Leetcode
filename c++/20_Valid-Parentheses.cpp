class Solution {
public:
    bool isValid(string s) {
        stack<char>stack;

        for(char c:s){
            switch(c){
                case ')':
                    if(stack.empty()||stack.top()!='(') return false;
                    stack.pop();
                    break;
                case ']':
                    if(stack.empty()||stack.top()!='[') return false;
                    stack.pop();
                    break;
                case '}':
                    if(stack.empty()||stack.top()!='{') return false;
                    stack.pop();
                    break;
                case '(':
                case '[':
                case '{':
                    stack.push(c);
                    break;
            }
        }
        return stack.empty() ? true : false;
    }
};