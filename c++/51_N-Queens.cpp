class Solution {
public:
    void backtrack(int n, vector<string>&board, vector<vector<string>>& result, int row, bitset<9>& row_contain, bitset<9>& col_contain, bitset<17>pDiag_contain, bitset<17>& nDiag_contain){
        if(row==n){
            result.push_back(board);
            return;
        }

        for(int col=0;col<n;++col){
            if(row_contain[row]||col_contain[col]||pDiag_contain[row+col]||nDiag_contain[row-col+n-1]) continue;

            row_contain.set(row);
            col_contain.set(col);
            pDiag_contain.set(row+col);
            nDiag_contain.set(row-col+n-1);

            board[row][col]='Q';
            backtrack(n, board, result, row+1, row_contain, col_contain, pDiag_contain, nDiag_contain);

            row_contain.reset(row);
            col_contain.reset(col);
            pDiag_contain.reset(row+col);
            nDiag_contain.reset(row-col+n-1);
            board[row][col]='.';

        }
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> result;
        //Inital a board
        vector<string> board(n, string(n, '.'));

        // Initialize bitset containers
        bitset<9> row_contain;
        bitset<9> col_contain;
        bitset<17> pDiag_contain;
        bitset<17> nDiag_contain;

        backtrack(n, board, result, 0, row_contain, col_contain, pDiag_contain, nDiag_contain);
        return result;
    }
};