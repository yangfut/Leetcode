class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid){
        int fish = grid[r][c];
        grid[r][c] = 0;
        // check 4 directions
        int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for(const auto& d : dir){
            int rr = r + d[0];
            int cc = c + d[1];
            if(rr < 0 || cc < 0 || rr == grid.size() || cc == grid[0].size()) continue;
            if(grid[rr][cc] == 0) continue;
            fish += dfs(rr,cc,grid);
        }
        return fish;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxFish = 0;
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < m; ++c){
                if(grid[r][c] == 0) continue;
                maxFish = max(maxFish, dfs(r,c,grid));
            }
        }
        return maxFish;
    }
};