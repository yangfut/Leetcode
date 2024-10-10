class NumMatrix {
public:
    int m,n;
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        // padding one row and col will be more efficient
        sum.resize(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; ++i){
            int temp = 0;
            for(int j = 1; j <= n; ++j){
                temp += matrix[i-1][j-1];
                sum[i][j] = temp + sum[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - (sum[row2+1][col1] + sum[row1][col2+1]) + sum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */