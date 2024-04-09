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

class Solution {
public:
    bool dfs(vector<vector<char>>& board, int row, int col, string word, int idx){
        if(row<0||col<0||row==board.size()||col==board[0].size()||board[row][col]!=word[idx]) return false;
        if(idx==word.size()-1) return true;

        char temp = board[row][col];
        board[row][col] = '@'; // visisted

        bool right = dfs(board, row+1, col, word, idx+1);
        bool left  = dfs(board, row-1, col, word, idx+1);
        bool up = dfs(board, row, col+1, word, idx+1);
        bool down = dfs(board, row, col-1, word, idx+1);

        board[row][col] = temp;
        return right || left || up || down;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int row=0;row<m;++row){
            for(int col=0;col<n;++col){
                if(board[row][col]!=word[0]) continue;
                if(dfs(board, row, col, word, 0)) return true;
            }
        }
        return false;
    }
};