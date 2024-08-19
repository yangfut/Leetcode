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

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;

        for(int i = 0; i < numRows; ++i){
            vector<int> one_line(i+1, 1);
            if(i>=2){
                for(int j = 1; j < i; ++j){
                    one_line[j] = output[i-1][j-1]+ output[i-1][j];
                }
            }
            output.push_back(one_line);
        }
        return output;
    }
};