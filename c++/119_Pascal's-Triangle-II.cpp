class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1, 0);
        row[0] = 1;
        for(int i = 0; i < rowIndex+1; ++i){
            // Update from right to left to avoid overwrite values
            for(int j = i; j > 0; --j){
                row[j] += row[j-1];
            }
        }
        return row;
    }
};