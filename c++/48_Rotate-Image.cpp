class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        //Transpse matrix
        int x = 0, y = 0;
        int temp;
        for(y = 0; y < n; y++){
            for(x = 0; x < y; x++){
                temp = matrix[x][y];
                matrix[x][y] = matrix[y][x];
                matrix[y][x] = temp;
            }
        }

        //Reserve matrix
        for(x=0; x<n; x++){
            for(y=0; y<n/2;y++){
                temp = matrix[x][y];
                matrix[x][y] = matrix[x][n-1-y];
                matrix[x][n-1-y] = temp;
            }
        }
    }
};