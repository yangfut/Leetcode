class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bitset<2>>>& flows, int row, int col, int OCEAN){
        if(flows[row][col].test(OCEAN)) return;

        const int m = heights.size(), n = heights[0].size();
        static const int r_offset[] = {-1, 0, 1, 0};
        static const int c_offset[] = {0, -1, 0, 1};

        flows[row][col].set(OCEAN);

        // Find the greater or equal heights
        for(int k = 0; k < 4; ++k){
            int r = r_offset[k], c = c_offset[k];
            if(row+r >= 0 && row+r < m && col+c >= 0 && col+c < n && heights[row+r][col+c] >= heights[row][col]){
                dfs(heights, flows, row+r, col+c, OCEAN);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty() || heights[0].empty()) return {};

        //Approcach: Conduct DFS with bitset to find greater height
        int m = heights.size(), n = heights[0].size();
        vector<vector<bitset<2>>> flows(m, vector<bitset<2>>(n, 0));

        // DFS for both oceans
        for(int col = 0; col < n; ++ col){
            dfs(heights, flows, 0, col, 0); //Pacific from Top
            dfs(heights, flows, m-1, col, 1); //Atlantic from bottom
        }

        for(int row = 0; row < m; ++row){
            dfs(heights, flows, row, 0, 0); //Pacific from left
            dfs(heights, flows, row, n-1, 1); //Atlantic from right
        }

        vector<vector<int>> result;
        for(int row = 0; row < m; ++row){
            for(int col = 0; col < n; ++col){
                if(flows[row][col].test(0) && flows[row][col].test(1)) result.push_back(vector<int>{row, col});
            }
        }
        return result;
    }
};