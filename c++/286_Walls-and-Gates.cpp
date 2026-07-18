class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int inf = INT_MAX, m = rooms.size(), n = rooms[0].size();
        queue<pair<int,int>> q;
        for(int r = 0; r < m; ++r){
            for(int c = 0; c < n; ++c){
                if(rooms[r][c] == 0) q.push({r,c});
            }
        }

        int d = 1;
        vector<pair<int,int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!q.empty()){
            int qSize = q.size();
            for(int i = 0; i < qSize; ++i){
                auto [r,c] = q.front(); q.pop();

                // Traverse
                for(int j = 0; j < dir.size(); ++j){
                    int nr = r + dir[j].first;
                    int nc = c + dir[j].second;
                    // boundary
                    if(nr >= m || nr < 0 || nc >= n || nc < 0) continue;
                    if(rooms[nr][nc] == inf){
                        rooms[nr][nc] = d;
                        q.push({nr,nc});
                    }
                }
            }
            ++d;
        }
    }
};