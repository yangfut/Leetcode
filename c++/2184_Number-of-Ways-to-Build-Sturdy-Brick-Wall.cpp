class Solution {
const int MOD = 1'000'000'007;
const int HASH_SIZE = 1024;
private:
    void precompute_crack_collection(int w, int width, vector<int>& bricks, vector<int>& crack_collection, int crack){
        
        //base case
        if(w == width){
            // exclude the edge crack
            crack &= ~(1 << width);
            crack_collection.push_back(crack);
            return;
        }

        for(int& b : bricks){
            if(w + b <= width){
                crack |= (1 << w+b);
                precompute_crack_collection(w+b, width, bricks, crack_collection, crack);
                crack &= ~(1 << w+b);
            }
        }

    }

    int backtrack(int h, int prev, vector<vector<int>>& dp, vector<int>& crack_collection){
        // base case
        if(h < 0) return 1;

        // memoization
        if(dp[h][prev] != -1) return dp[h][prev];

        int temp_ans = 0;
        for(int& crack : crack_collection){
            if((crack & prev) == 0){
                temp_ans = (temp_ans + backtrack(h-1, crack, dp, crack_collection)) % MOD;
            }
        }

        return dp[h][prev] = temp_ans;

    }
public:
    int buildWall(int height, int width, vector<int>& bricks) {
        // 1. 2D-DP to record the possibilites
        // 2. Create a bitmask to record the crack
        // 3. backtrack

        vector<int> crack_collection;
        precompute_crack_collection(0, width, bricks, crack_collection, 0);
        vector<vector<int>> dp(height, vector<int>(HASH_SIZE,-1));

        return backtrack(height-1, 0, dp, crack_collection);
    }
};