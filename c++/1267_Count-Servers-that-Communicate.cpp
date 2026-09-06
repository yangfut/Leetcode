// Union-Find
class Solution {
public:
    int find(int x, unordered_map<int,int>& group){
        if(!group.count(x)) group[x] = x;
        if(group[x] != x) group[x] = find(group[x], group);
        return group[x];
    }

    void unite(int x, int y, unordered_map<int,int>& group){
        int rx = find(x, group);
        int ry = find(y, group);
        if(rx == ry) return;
        if(ry < rx) swap(rx, ry);
        group[ry] = rx;
    }
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,int> group;
        int n = grid.size(), m = grid[0].size();
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < m; ++c){
                if(grid[r][c] == 1){
                    unite(r, ~c, group);
                }
            }
        }

        unordered_map<int,int>cnt;
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < m; ++c){
                if(grid[r][c] == 1){
                    int root = find(r,group);
                    ++cnt[root];
                }
            }
        }
        int connected = 0;
        for(auto num : cnt){
            if(num.second == 1) continue;
            connected += num.second;
        }
        return connected;
    }
};

// DFS
class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        int cnt = 1;
        // horizontal scan
        for(int c = 0; c < m; ++c){
            if(grid[row][c] == 1){
                grid[row][c] = -1; // Mark as visited
                cnt += dfs(row,c, grid);
            }
        }
        // vertical scan
        for(int r = 0; r < n; ++r){
            if(grid[r][col] == 1){
                grid[r][col] = -1; // Mark as visited
                cnt += dfs(r,col,grid);
            }
        }
        return cnt;
    }
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int connected = 0;
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < m; ++c){
                if(grid[r][c] == 1){
                    grid[r][c] = -1; // Mard as visited
                    int cnt = dfs(r,c,grid);
                    if(cnt > 1) connected += cnt;
                }
            }
        }
        return connected;
    }
};