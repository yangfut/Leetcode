class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        deque<pair<int,int>> deq;
        deq.push_back(make_pair(0,0));
        dist[0][0] = grid[0][0];
        int r[4] = {-1, 0, 1, 0};
        int c[4] = {0, -1, 0, 1};
        
        while(!deq.empty()){
            pair<int,int> p = deq.front();
            deq.pop_front();

            for(int k = 0; k < 4; ++k){
                int new_r = p.first + r[k];
                int new_c = p.second + c[k];
                if(new_r < 0 || new_r == n || new_c < 0 || new_c == n) continue;

                int new_dist = max(grid[new_r][new_c], dist[p.first][p.second]);
                if(new_dist < dist[new_r][new_c]){
                    dist[new_r][new_c] = new_dist;
                    if(!deq.empty() && grid[new_r][new_c] < grid[deq.front().first][deq.front().second]){
                        deq.push_front(make_pair(new_r, new_c));
                    }else{
                        deq.push_back(make_pair(new_r, new_c));
                    }
                }
            }

        }

        return dist[n-1][n-1];
    }
};