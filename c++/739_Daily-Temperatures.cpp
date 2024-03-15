class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //1. backward from n-1 to 0
        //2. Store temperature in an ascending order in stack
            //If current temperature is greater than stack.top(), stack.pop()
            //If current tempature is smaller than stack.top(), stack.push(i)
        //3. ans[i] = (stack.empty()) ? 0 : stack.top() - i

        int n=temperatures.size();
        stack<int>stack;
        vector<int>ans(n);
        for(int i=n-1;i>=0;--i){
            while(!stack.empty()&&temperatures[i]>=temperatures[stack.top()]) stack.pop();
            
            ans[i] = (stack.empty())?0:stack.top()-i;
            stack.push(i);
        }
        return ans;
    }
};