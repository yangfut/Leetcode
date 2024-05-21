class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        // The reason that backtrack doesn't work is that the direction can move up and left.
        // If there's two direction one is up and one is down, the grid[row][col] is determined by which source is comming first

        // Dijstrak algorithm to find minimum path
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int,int>> deq;

        dist[0][0] = 0;
        deq.push_back(make_pair(0,0));

        int r[4] = {0, -1, 0, 1};
        int l[4] = {-1, 0, 1, 0};

        while(!deq.empty()){
            pair<int,int>p = deq.front();
            deq.pop_front();

            // traverse all the adjacent nodes
            for(int k = 0; k < 4; ++k){
                int row = p.first + r[k];
                int col = p.second + l[k];

                // out of bound
                if(row < 0 || col < 0 || row == m || col == n) continue;

                int new_dist = dist[p.first][p.second] + grid[row][col];
                if(new_dist < dist[row][col]){
                    dist[row][col] = new_dist;
                    // handle the case where there is no obstacle is at the current cell
                    if(grid[row][col] == 0) deq.push_front(make_pair(row, col));
                    if(grid[row][col] == 1) deq.push_back(make_pair(row, col));
                }
            }
        }
        return dist[m-1][n-1];
    }
};