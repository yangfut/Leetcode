class Solution {
public:
    bool dfs(int r, int c,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        int m = grid2.size(), n = grid2[0].size();
        // Mark as visited
        grid2[r][c] = 0;
        bool isSub = grid1[r][c] == 1;

        int rdir[] = {-1,0,1,0};
        int cdir[] = {0,-1,0,1};
        for(int i = 0; i < 4; ++i){
            int nr = r + rdir[i];
            int nc = c + cdir[i];
            if(nr < 0 || nc < 0 || nr == m || nc == n || grid2[nr][nc] == 0) continue;
            isSub &= dfs(nr,nc,grid1,grid2);
        }
        return isSub;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // DFS on grid2 to ensure all lands in grid2 are covered by grid1 island
        int m = grid1.size(), n = grid1[0].size();
        int cnt = 0;
        for(int r = 0; r < m; ++r){
            for(int c = 0; c < n; ++c){
                if(grid2[r][c] == 1){
                    if(dfs(r,c,grid1,grid2)){
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }
};