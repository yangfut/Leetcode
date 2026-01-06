class TicTacToe {
public:
    vector<int> grid;
    int _n;

    TicTacToe(int n) {
        grid.resize(n*n);
        _n = n;
    }
    
    bool is_won_by_horizontal(int row, int col){
        int val = grid[row*_n+col];
        for(int i = 0; i < _n; ++i){
            if(grid[row*_n + i] != val) return false;
        }
        return true;
    }

    bool is_won_by_vertical(int row, int col){
        int val = grid[row*_n+col];
        for(int i = 0; i < _n; ++i){
            if(grid[i*_n + col] != val) return false;
        }
        return true;
    }

    bool is_won_by_diagonal(int row, int col){
        if(row != col && row+col != (_n-1)) return false;
        int val = grid[row*_n+col];
        bool is_forward = true;
        bool is_backward = true;

        for(int i = 0; i < _n && is_forward; ++i){
            if(grid[i*_n + i] != val) is_forward = false;
        }
        
        for(int i = 0; i < _n && is_backward; ++i){
            if(grid[i*_n + (_n-i-1)] != val) is_backward = false;
        }
        return is_forward || is_backward;
    }
    int move(int row, int col, int player) {
        grid[row*_n+col] = player;
        if (is_won_by_horizontal(row, col) || is_won_by_vertical(row, col) || is_won_by_diagonal(row, col)) return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

 class TicTacToe {
public:
    vector<int> rowsSum, colsSum;
    int diag = 0, anti = 0, _n;
    TicTacToe(int n): _n(n), rowsSum(n, 0), colsSum(n, 0) {}
    
    int move(int row, int col, int player) {
        int val = (player == 1) ? 1 : -1;
        rowsSum[row] += val;
        colsSum[col] += val;
        if(row == col) diag += val;
        if(row+col == (_n-1)) anti += val;

        if(abs(rowsSum[row]) == _n || abs(colsSum[col]) == _n || abs(diag) == _n || abs(anti) == _n)
            return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */