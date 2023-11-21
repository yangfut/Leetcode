#include <string>
#include <stack>

class Solution {
public:
    string convertToTitle(int columnNumber) {
        int quotient;
        int remainder;
        stack<int> st;
        string s;

        while(columnNumber != 0){
            quotient = columnNumber / 26;
            remainder = columnNumber % 26;
            if(remainder == 0){
                quotient--;
                remainder+=26;
            }
            st.push(remainder);
            columnNumber = quotient;
        }
        
        while(!st.empty()){
            s += (char)(st.top()+64);
            st.pop();
        }
        return s;
    }
};