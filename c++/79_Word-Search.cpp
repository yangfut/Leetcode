class Solution {
public:
    bool dfs_recursion(vector<vector<char>>& board, string word, int row, int col, int ptr) {
        //Found word
        if(ptr==word.size()) return true;
        //Base case
        if(row<0||col<0||row==board.size()||col==board[0].size()) return false;
        if(board[row][col]!=word[ptr]) return false;

        board[row][col]='-';
        bool result = dfs_recursion(board, word, row+1, col, ptr+1)
                    || dfs_recursion(board, word, row, col+1, ptr+1)
                    || dfs_recursion(board, word, row-1, col, ptr+1)
                    || dfs_recursion(board, word, row, col-1, ptr+1);
        board[row][col]=word[ptr];
        return result;

    }
    bool dfs_sol(vector<vector<char>>& board, string word) {
        
        for(int row=0; row<board.size(); row++){
            for(int col=0; col<board[0].size(); col++){
                if(board[row][col]==word[0]&&dfs_recursion(board, word, row, col, 0)) return true;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        //#1 Recursive
        //TC:O(NMK), SC:O(1)
        return dfs_sol(board, word);
    }
};