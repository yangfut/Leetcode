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