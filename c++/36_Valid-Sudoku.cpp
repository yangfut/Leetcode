class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check sub-box
        // Search (0,0)->(0,3)->(0,6)->(3,0) -> ...
        for(int row=0;row<9;row+=3){
            for(int col=0;col<9;col+=3){
                vector<int>hash_table(10,0);
                for(int i=0;i<3;++i){
                    for(int j=0;j<3;++j){
                        if(board[row+i][col+j]=='.') continue;
                        if(hash_table[board[row+i][col+j]-'0']==1) return false;
                        hash_table[board[row+i][col+j]-'0']=1;
                    }
                }
            }
        }

        // Check every row
        // Search (0,0:8)->(1,0:8)->(2,0:8)-> ...
        for(int row=0;row<9;++row){
            vector<int>hash_table(10,0);
            for(int j=0;j<9;++j){
                if(board[row][j]=='.') continue;
                if(hash_table[board[row][j]-'0']==1) return false;
                hash_table[board[row][j]-'0']=1;
            }
        }
        // Check every column
        // Search (0:8,0)->(0:8,1)->(0:8,2)-> ...
        for(int col=0;col<9;++col){
            vector<int>hash_table(10,0);
            for(int i=0;i<9;++i){
                if(board[i][col]=='.') continue;
                if(hash_table[board[i][col]-'0']==1) return false;
                hash_table[board[i][col]-'0']=1;
            }
        }
        return true;
    }
};