class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        unordered_map<int,int> join;
        for(int row = 0; row < wall.size(); ++row){
            int sum = 0;

            // Don't calculate the join at the edge of wall, so decrement by 1
            for(int col = 0; col < wall[row].size() - 1; ++col){
                sum += wall[row][col];
                ++join[sum];
            }
        }

        int crossed_bricks = INT_MAX;
        for(auto it = join.begin(); it != join.end(); ++it){
            crossed_bricks = min(crossed_bricks, n - it->second);
        }
        return crossed_bricks == INT_MAX ? n : crossed_bricks;
    }
};

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> edges;
        for(int i = 0; i < wall.size(); ++i){
            int offset = 0;
            for(int j = 0; j < wall[i].size()-1; ++j){
                offset += wall[i][j];
                edges[offset]++;
            }
        }

        int maxVal = 0;
        for(auto edge : edges) maxVal = max(maxVal, edge.second);

        return wall.size() - maxVal;
    }
};