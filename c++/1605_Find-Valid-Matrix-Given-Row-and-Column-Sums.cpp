class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> matrix(m, vector<int>(n, 0));

        for(int row = 0; row < m; ++row){
            for(int col = 0; col < n; ++col){
                matrix[row][col] = min(rowSum[row], colSum[col]);
                rowSum[row] -= matrix[row][col];
                colSum[col] -= matrix[row][col];
            }
        }

        return matrix;
    }
};