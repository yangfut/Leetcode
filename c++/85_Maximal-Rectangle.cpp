class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // 1. Take histogram layer-by-layer - O(m)
        // 2. Determine the width of ractangle by taking next_less_element and previous_less_element - O(n)

        // TC: O(M*N)
        int m = matrix.size(), n = matrix[0].size(), maxArea = 0;
        vector<int> hist(n);

        for(int row = 0; row < m; ++row){
            for(int col = 0; col < n; ++col){
                hist[col] = (matrix[row][col] == '0') ? 0 : ++hist[col];
            }

            stack<int> stack1;
            vector<int> ple(n); // previous less element

            stack<int> stack2;
            vector<int> nle(n); // next less element
            for(int col = 0; col < n; ++col){
                while(!stack1.empty() && hist[col] <= hist[stack1.top()]) stack1.pop();
                ple[col] = stack1.empty() ? -1 : stack1.top();
                stack1.push(col);
            }

            for(int col = n-1; col >= 0; --col){
                while(!stack2.empty() && hist[col] <= hist[stack2.top()]) stack2.pop();
                nle[col] = stack2.empty() ? n : stack2.top();
                stack2.push(col);
            }

            for(int col = 0; col < n; ++col){
                maxArea = max(maxArea, hist[col] * (nle[col] - ple[col] - 1));
            }
        }
        return maxArea;
    }
};