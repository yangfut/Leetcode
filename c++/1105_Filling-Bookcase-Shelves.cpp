class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n  = books.size();
        vector<int> dp(n, INT_MAX);
        for(int i = 0; i < n; ++i){
            int w = 0, h = 0;
            // Recalculate the height in the last layer
            for(int j = i; j >= 0; --j){
                w += books[j][0];
                if(w > shelfWidth) break;
                h = max(books[j][1], h);
                int prevHeight = (j > 0) ? dp[j-1] : 0;
                dp[i] = min(prevHeight + h, dp[i]);
            }
        }
        return dp[n-1];
    }
};