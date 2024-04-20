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

class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col){
        
        board[row][col] = '@';
        const int m = board.size(), n = board[0].size();
        static const int r_offset[] = {-1, 0, 1, 0};
        static const int c_offset[] = {0, -1, 0, 1};

        for(int k = 0; k < 4; ++k){
            int r = r_offset[k], c = c_offset[k];

            if(row+r >=0 && row+r < m && col+c >= 0 && col+c < n && board[row+r][col+c] == 'O'){
                dfs(board, row+r, col+c);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        // Think like Pacific/Atlantic Ocean Problem

        // 1. Conduct DFS from boarder cells
        // 2. Mark the touched 'O' into '@'
        // 3. Then, finally turn all 'O' to 'X' and '@' to 'O'
        if(board.empty() || board[0].empty()) return;

        int m = board.size(), n = board[0].size();

        for(int col = 0; col < n; ++col){
            if(board[0][col] == 'O') dfs(board, 0, col);
            if(board[m-1][col]=='O') dfs(board, m-1, col);
        }

        for(int row = 0; row < m; ++row){
            if(board[row][0] == 'O') dfs(board, row, 0);
            if(board[row][n-1] == 'O') dfs(board, row, n-1);
        }

        for(int row = 0; row < m; ++row){
            for(int col = 0; col < n; ++col){
                if(board[row][col] == 'X') continue;
                if(board[row][col] == 'O'){
                    board[row][col] = 'X';
                }else{
                    board[row][col] = 'O';
                }
            }
        }
    }
};