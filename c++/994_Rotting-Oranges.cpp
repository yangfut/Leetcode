class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // 1. Do BFS and count every iteration
        queue<pair<int,int>>que;
        int iteration = -1;
        int m = grid.size(), n = grid[0].size();
        int re = n * m;
        for(int row = 0; row < m; ++row){
            for(int col = 0; col < n; ++col){
                if(grid[row][col] == 0) --re;
                else if(grid[row][col] == 2) que.push(pair<int,int>{row, col});
            }
        }

        // Edge case: No orange exists
        if(re == 0) return 0;

        int r_offset[] = {-1, 1, 0, 0};
        int c_offset[] = {0, 0, -1, 1};

        while(!que.empty()){
            int size = que.size();
            re -= size;
            ++iteration;

            // Once rotting
            for(int j = 0; j < size; ++j){
                int row = que.front().first;
                int col = que.front().second;
                que.pop();

                for(int k = 0; k < 4; ++k){
                    int r = r_offset[k];
                    int c = c_offset[k];

                    if(row+r < 0 || row+r == m || col+c < 0 || col+c == n) continue;
                    if(grid[row+r][col+c] == 1){
                        grid[row+r][col+c] = 2;
                        que.push(pair<int, int>{row+r, col+c});
                    }
                
                }
            }
        }

        return re == 0 ? iteration : -1;
    }
};