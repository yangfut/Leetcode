class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int dist = -1, n = grid.size();
        queue<pair<int,int>> q;
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < n; ++c){
                if(grid[r][c] == 1) q.push({r,c});
            }
        }

        vector<pair<int,int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        if(q.size() == n*n || q.empty()) return -1;

        while(!q.empty()){
            ++dist;
            int qsize = q.size();
            for(int i = 0; i < qsize; ++i){
                auto [r, c] = q.front();
                q.pop();

                for(auto [_r, _c] : dir){
                    int post_r = r+_r;
                    int post_c = c+_c;
                    if(post_r >= n || post_r < 0 || post_c >= n || post_c < 0) continue;
                    if(grid[post_r][post_c] == 0){
                        grid[post_r][post_c] = -1;
                        q.push({post_r, post_c});
                    }
                }
            }
        }
        return dist;
    }
};