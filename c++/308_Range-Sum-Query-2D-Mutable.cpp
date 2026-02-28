class NumMatrix {
public:

    vector<vector<int>> m;
    vector<vector<int>> rsm;

    NumMatrix(vector<vector<int>>& matrix) {
        // full copy matrix
        m = matrix;
        rsm = matrix;

        // initilize sum
        for(int row = 0; row < m.size(); ++row){
            for(int col = 0; col < m[0].size(); ++col){
                rsm[row][col] = (col == 0) ? rsm[row][col] : rsm[row][col-1] + rsm[row][col];
            }
        }
    }
    
    void update(int row, int col, int val) {
        int delta = val - m[row][col];
        m[row][col] = val;
        for(int c = col; c < m[0].size(); ++c){
            rsm[row][c] += delta;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int row = row1; row <= row2; ++row){
            sum += rsm[row][col2];
            if(col1 - 1 >= 0) sum -= rsm[row][col1-1];
        }
        return sum;
    }
};

// Fenwick tree solution
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */


 class NumMatrix {
private:
    int preSum(int rr, int cc){
        int sum = 0;
        for(int r = rr; r > 0; r -= (r & -r)){
            for(int c = cc; c > 0; c -= ( c & -c)){
                sum += fenwick[r][c];
            }
        }
        return sum;
    }
public:
    vector<vector<int>> mm;
    vector<vector<int>> fenwick;
    int n, m;
    NumMatrix(vector<vector<int>>& matrix) {
        // make m 1-based matrix
        n = matrix.size();
        m = matrix[0].size();
        mm.resize(n+1, vector<int>(m+1, 0));
        fenwick.resize(n+1, vector<int>(m+1, 0));

        for(int r = 0; r < n; ++r){
            for(int c = 0; c < m; ++c){
                update(r, c, matrix[r][c]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int rr = row + 1, cc = col + 1;
        int delta = val - mm[rr][cc];
        mm[rr][cc] += delta;
        for(int r = rr; r <= n; r += (r & -r)){
            for(int c = cc; c <= m; c += (c & -c)){
                fenwick[r][c] += delta;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int rr1 = row1+1, rr2 = row2+1, cc1 = col1+1, cc2 = col2+1;
        return preSum(rr2, cc2) - preSum(rr1-1, cc2) - preSum(rr2, cc1-1) + preSum(rr1-1, cc1-1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */