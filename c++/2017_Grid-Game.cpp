#define LL long long
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        // Player 2 can obtain points in the region between the rest of upperprefix[i] and lowerprefix[i-1]
        // i is the switching point for Player 1

        int n = grid[0].size();
        vector<LL> upperprefix(n,grid[0][0]), lowerprefix(n, grid[1][0]);

        for(int i = 1; i < n; ++i){
            upperprefix[i] = upperprefix[i-1] + grid[0][i];
            lowerprefix[i] = lowerprefix[i-1] + grid[1][i];
        }

        // Evaluate if Player 1 take the switching point at index i, how many points can Player 2 get in the remian grids
        LL ans = LLONG_MAX;
        for(int i = 0; i < n; ++i){
            LL from_lower = (i-1 >= 0) ? lowerprefix[i-1] : 0;
            LL from_upper = upperprefix[n-1] - upperprefix[i];
            ans = std::min(ans, std::max(from_lower, from_upper));
        }
        return ans;
    }
};