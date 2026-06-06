class Solution {
public:
    // Find islands
    // Expand one layer by layer until find grid[r][c] == 1
    void dfs(vector<vector<int>>& grid, int r, int c, queue<pair<int,int>>& q){
        int n = grid.size();
        if(r < 0 || c < 0 || r >= n || c >= n) return;

        if(grid[r][c] == 0 || grid[r][c] == 2) return;

        grid[r][c] = 2; // visited
        q.push({r, c});
        dfs(grid, r+1, c, q);
        dfs(grid, r, c+1, q);
        dfs(grid, r-1, c, q);
        dfs(grid, r, c-1, q);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool found = false;
        queue<pair<int,int>> q;
        for(int r = 0; r < n && !found; ++r){
            for(int c = 0; c < n && !found; ++c){
                if(grid[r][c] == 1){
                    found = true;
                    dfs(grid, r, c, q);
                }
            }
        }

        int step = 0;
        vector<pair<int, int>> dir = {{0,1}, {1,0}, {-1, 0}, {0,-1}};
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; ++i){
                auto [r, c] = q.front();
                q.pop();
                
                for(int j = 0; j < 4; ++j){
                    int nr = r + dir[j].first;
                    int nc = c + dir[j].second;
                    if(nr >= n || nc >= n || nr < 0 || nc < 0) continue;
                    if(grid[nr][nc] == 1) return step;
                    if(grid[nr][nc] == 0){
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
            ++step;
        }

        return -1;
    }
};