class Solution {
public:
    int getLiveNeighbor(vector<vector<int>>& board, int x, int y){
        int sum=0;
        int boundx = board.size();
        int boundy = board[0].size();

        for(int idx_x = x-1; idx_x <= x+1; idx_x++){
            for(int idx_y = y-1; idx_y <= y+1; idx_y++){
                if(idx_x < 0 || idx_x >= boundx || idx_y < 0 || idx_y >= boundy || (idx_x == x && idx_y == y)) continue;
                sum += board[idx_x][idx_y];
            }
        }
        return sum;
    }
    //Brute-Force
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> result(board.size(), vector<int>(board[0].size(), 0));

        int data;
        for(int x = 0; x < board.size(); x++){
            for(int y = 0; y < board[0].size(); y++){
                data = getLiveNeighbor(board, x, y);
                if(data < 2 || data > 3){
                    result[x][y] = 0;
                }else if(data == 3){
                    result[x][y] = 1;
                }else{
                    result[x][y] = board[x][y];
                }
            }
        }

        for(int x = 0; x < board.size(); x++){
            for(int y = 0; y < board[0].size(); y++){
                board[x][y] = result[x][y];
            }
        }
    }
};