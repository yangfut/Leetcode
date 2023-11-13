class Solution {
public:    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri(numRows, vector<int>(numRows, 1));

        for(int row = 0; row < numRows; row++) {
            tri[row].resize(row+1, 1);
        }

        if(numRows > 2) {
            for(int row = 0; row < numRows; row++) {
                for(int idx = 1; idx < row; idx++) {
                    tri[row][idx] = tri[row-1][idx-1] + tri[row-1][idx];
                }
            }
        }
        return tri;
    }
};