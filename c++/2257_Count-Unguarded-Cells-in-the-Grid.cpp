class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Memory optimization
        vector<char> grid(m*n, 0);

        auto idx = [&](const int r, const int c){return r*n+c;};
        // 1 = wall, 2 = guard, 3 = watched
        for(auto& p : guards) grid[idx(p[0], p[1])] = 2;
        for(auto& p : walls) grid[idx(p[0], p[1])] = 1;

        // horizontal sweep
        for(int row = 0; row < m; ++row){
            bool seen = false;
            // sweep from left to right
            for(int col = 0; col < n; ++col){
                char& cell = grid[idx(row, col)];
                if(cell == 1) seen = false;
                else if(cell == 2) seen = true;
                else if(seen && cell == 0) cell = 3;
            }
            seen = false;
            // sweep from right ot left
            for(int col = n-1; col >= 0; --col){
                char& cell = grid[idx(row, col)];
                if(cell == 1) seen = false;
                else if(cell == 2) seen = true;
                else if(seen && cell == 0) cell= 3;
            }
        }
        
        // vertical sweep
        for(int col = 0; col < n; ++col){
            bool seen = false;
            // sweep from top to bottom
            for(int row = 0; row < m; ++row){
                char& cell = grid[idx(row, col)];
                if(cell == 1) seen = false;
                else if(cell == 2) seen = true;
                else if(seen && cell == 0) cell = 3;
            }
            seen = false;
            // sweep from bottom to top
            for(int row = m-1; row >= 0; --row){
                char& cell = grid[idx(row, col)];
                if(cell == 1) seen = false;
                else if(cell == 2) seen = true;
                else if(seen && cell == 0) cell = 3;
            }
        }

        int acc = 0;
        for(int row = 0; row < m; ++row) for(int col = 0; col < n; ++col) if(grid[idx(row, col)] == 0) ++acc;
        return acc;
    }
};