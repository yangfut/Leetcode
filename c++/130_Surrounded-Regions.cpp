class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col){
        //Base case
        if(row<0||col<0||row==board.size()||col==board[0].size()) return;
        if(board[row][col]!='O') return;
        board[row][col]='-';
        dfs(board, row+1, col);
        dfs(board, row-1, col);
        dfs(board, row, col+1);
        dfs(board, row, col-1);
        return;
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        //Mark all the 'O' connected to board and turn into '-'
        //Top/Bottom
        for(int i=0;i<n;i++){
            if(board[0][i]=='O') dfs(board, 0, i);
            if(board[m-1][i]=='O') dfs(board, m-1,i); 
        }

        //Left/Right
        for(int i=1;i<m-1;i++){
            if(board[i][0]=='O') dfs(board, i, 0);
            if(board[i][n-1]=='O') dfs(board, i, n-1);
        }

        //Make all the 'X'&'O' into X
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(board[row][col]!='-') board[row][col]='X';
                else board[row][col]='O';
            }
        }
        return;
    }
};