class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(), m = n * n;
        vector<int> ans(2);
        vector<bool> freq(m+1);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int val = grid[i][j];
                if(freq[val] == true) ans[0] = val;
                else freq[val] = true;
            }
        }

        for(int i = 1; i < m+1; ++i){
            if(freq[i]== false) ans[1] = i;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;
        int expectedSum = total * (total+1) / 2;
        int actualSum = 0, twiceNumber = 0, missingNumber = 0;
        vector<bool> visited(total+1);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int val = grid[i][j];
                if(visited[val] == true) twiceNumber = val;
                visited[val] = true;
                actualSum += val;
            }
        }

        missingNumber = expectedSum - (actualSum - twiceNumber);
        return {twiceNumber, missingNumber};
    }
};