#include<stack>
#include<vector>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Monotonic increasing
        // 1. Append 0 to find peak when every inputs is in stack
        // 2. Use PLE and find peak when input heights is not increasing
        // 3. Calculate the area for each peak
            // height[stack.top()]; stack.pop();
            // area = height[stack.top()] * (i-1-stack.top()) //Not include i and stack.top()
            // area = height[stack.top()] * (i-1-(-1)) //Not include i and 0

        int n=heights.size();
        stack<int>stack;
        int curArea;
        int maxArea = 0;
        heights.push_back(0);
        for(int i=0;i<=n;++i){
            //Previous Less Elements(PLE)
            while(!stack.empty()&&heights[stack.top()]>heights[i]){
                int peak = heights[stack.top()];
                stack.pop();
                if(!stack.empty()){
                    curArea = peak * (i-1-stack.top());
                }else{
                    curArea = peak * i;
                }
                if(curArea>maxArea) maxArea = curArea;
            }
            stack.push(i);
        }
        return maxArea;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // next less element
        vector<int> nle(n, n);
        stack<int> st;
        for(int i = n-1; i >= 0; --i){
            int curr = heights[i];
            while(!st.empty() && curr <= heights[st.top()]) st.pop();
            if(!st.empty()){
                nle[i] = st.top();
            }
            st.push(i);
        }
        st = {};

        // previous less element
        vector<int> ple(n, -1);
        for(int i = 0; i < n; ++i){
            int curr = heights[i];
            while(!st.empty() && curr <= heights[st.top()]) st.pop();
            if(!st.empty()){
                ple[i] = st.top();
            }
            st.push(i);
        }

        // find area
        int area = 0;
        for(int i = 0; i < n; ++i){
            int h = heights[i];
            area = max(area, (nle[i] - ple[i] - 1) * h);
        }
        return area;
    }
};