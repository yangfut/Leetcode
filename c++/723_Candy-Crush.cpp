class Solution {
public:
    bool dfs(vector<vector<int>>& board, vector<vector<int>>& status, int r, int c, int dr, int dc, int len){
        int m = board.size(), n = board[0].size();
        if(r+dr >= m || c+dc >= n) return false;
        if(board[r][c] == 0 || board[r+dr][c+dc] == 0) return false;
        if(board[r][c] != board[r+dr][c+dc]) return false;

        // cache
        int direction = (dr == 1 && dc == 0) ? 2 : 1;
        if((status[r+dr][c+dc] & direction) == direction) return true;
        
        if(dfs(board, status, r+dr, c+dc, dr, dc, len+1) || len + 1 >= 3) {
            status[r][c] |= direction;
            status[r+dr][c+dc] |= direction;
            return true;
        }
        return false;
    }
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        bool hit;

        do{
            hit = false;
            // bit 0: horizontal crushed, bit 1: vertical crushed
            vector<vector<int>> status(m, vector<int>(n, 0));
            // hit - horizontal
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    if(dfs(board, status, i, j, 0, 1, 1)){
                        status[i][j] |= 1;
                        hit = true;
                    }
                }
            }
            // hit - vertical
            for(int j = 0; j < n; ++j){
                for(int i = 0; i < m; ++i){
                    if(dfs(board, status, i, j, 1, 0, 1)){
                        status[i][j] |= 2;
                        hit = true;
                    };
                }
            }
            // gravity
            vector<int>shift(n, 0);
            for(int i = m-1; i >= 0; --i){
                for(int j = 0; j < n; ++j){
                    if(status[i][j]){
                        board[i][j] = 0;
                        ++shift[j];
                    }else if(shift[j]){
                        int tRow = shift[j];
                        board[i+tRow][j] = board[i][j];
                        board[i][j] = 0;
                    }
                }
            }
            // show(board);
        }while(hit);


        return board;
    }
};