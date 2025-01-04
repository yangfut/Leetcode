//TC: O(NM^2), SC: O(NM)
class Solution {
    int querySum(const pair<int,int> &r1, const pair<int,int> &r2, vector<vector<int>> &sumTable){
        int Pos2X = r2.first, Pos2Y = r2.second;
        int Pos1X = r1.first, Pos1Y = r1.second;

        int bottomRight = sumTable[Pos2X][Pos2Y];
        int topRight = (Pos1X) ? sumTable[Pos1X-1][Pos2Y] : 0;
        int bottomLeft = (Pos1Y) ? sumTable[Pos2X][Pos1Y-1] : 0;
        int topLeft = (Pos1X && Pos1Y) ? sumTable[Pos1X-1][Pos1Y-1] : 0;

        return bottomRight - topRight - bottomLeft + topLeft;
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> sumTable(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int top = i > 0 ? sumTable[i-1][j] : 0;
                int left = j > 0 ? sumTable[i][j-1] : 0;
                int topLeft = (i > 0 && j > 0) ? sumTable[i-1][j-1] : 0;
                sumTable[i][j] = top + left - topLeft + matrix[i][j];
                // cout << sumTable[i][j] << " ";
            }
            // cout << endl;
        }
        int c = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                pair<int,int> r1 = {i, j};

                for(int k = i; k < n; ++k){
                    for(int l = j; l < m; ++l){
                        pair<int,int> r2 = {k, l};
                        if(querySum(r1, r2, sumTable) == target){
                            ++c;
                        }
                    }
                }

            }
        }
        return c;
    }
};

//TC: O(N*M^2), SC:O(N)
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        // accumulate sum for each row
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; ++i){
            for(int j = 1; j < m; ++j){
                matrix[i][j] += matrix[i][j-1];
            }
        }

        int valid = 0;
        // Between col1 and col2, check if any sum of the row matches the target
        for(int col1 = 0; col1 < m; ++col1){
            for(int col2 = col1; col2 < m; ++col2){
                unordered_map<int,int> preSumFreq;
                preSumFreq[0] = 1;
                int currSum = 0;
                for(int row = 0; row < n; ++row){
                    currSum += matrix[row][col2] - ((col1 > 0) ? matrix[row][col1-1] : 0);

                    if(preSumFreq.find(currSum - target) != preSumFreq.end()){
                        valid += preSumFreq[currSum - target];
                    }

                    preSumFreq[currSum]++;
                }
            }

        }

        return valid;
    }
};