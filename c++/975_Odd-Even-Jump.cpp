class Solution {
const int EVEN_JUMP = 0;
const int ODD_JUMP = 1;
private:
    int backtrack(vector<int>& arr, vector<vector<int>>& dp, vector<vector<int>>& next_move, int idx, int jump){
        
        // base case
        if(idx == arr.size() - 1) return 1;

        // memoization
        if(dp[idx][jump] != -1) return dp[idx][jump];

        if(next_move[idx][jump] == idx) return dp[idx][jump] = 0;

        return dp[idx][jump] = backtrack(arr, dp, next_move, next_move[idx][jump], !jump);
    }
public:
    int oddEvenJumps(vector<int>& arr) {
        
        // backtrack with memoization
        int n = arr.size(), count = 0;
        vector<vector<int>> dp(n, vector<int>(2,-1));
        vector<vector<int>> next_move(n, vector<int>(2,-1));
        
        map<int,int> mapToIdx;
        mapToIdx[INT_MAX] = n;
        mapToIdx[INT_MIN] = n;
        for(int i = n-1; i >=0; --i){

            auto it = mapToIdx.lower_bound(arr[i]);
            // next_move[1] is the next smallest greater or equal lement. e.g. arr[i] <= arr[j]
            next_move[i][ODD_JUMP] = it->second == n ? i : it->second;

            if(it->first > arr[i]) --it;
            // next_move[0] is the next largest smaller or equal element. e.g. arr[i] >= arr[j]
            next_move[i][EVEN_JUMP] = it->second == n ? i : it->second;

            // Question ask to take the smallest index if there's multiple valid next_move
            mapToIdx[arr[i]] = i;
        }

        for(int idx = 0; idx < n; ++idx){
            if(backtrack(arr, dp, next_move, idx, ODD_JUMP)) ++count;
        }

        return count;
    }
};