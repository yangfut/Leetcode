class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> up(m+1, vector<int>(n+1,0));
        vector<vector<int>> left(m+1, vector<int>(n+1,0));
        int maxSq = 0;
        for(int r = 0; r < m; ++r){
            for(int c = 0; c < n; ++c){
                if(grid[r][c] == 0){
                    up[r+1][c+1] = 0;
                    left[r+1][c+1] = 0;
                }else{
                    up[r+1][c+1] = up[r][c+1] + 1;
                    left[r+1][c+1] = left[r+1][c] + 1;

                    int slide = min(up[r+1][c+1], left[r+1][c+1]);
                    // for loop here is for this situation
                    // 0 0 1
                    // 0 1 1
                    // 1 1 1
                    for(int s = slide; s > maxSq; --s){
                        if(c+2-s < 0 || r+2-s < 0) continue;
                        if(up[r+1][c+2-s] < s || left[r+2-s][c+1] < s) continue;
                        maxSq = s;
                    }
                }
            }
        }
        return maxSq * maxSq;
    }
};