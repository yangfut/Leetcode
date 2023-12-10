class Solution {
public:
    void genPascalsTriangle(int numRows, vector<vector<int>>&triangle, int layer){
        if(layer >= numRows) return;

        int length = layer+1;
        vector<int> vi(length, 1);
        for(int idx=1; idx < length-1; idx++){
            vi[idx] = triangle[layer-1][idx-1] + triangle[layer-1][idx];
        }
        triangle.push_back(vi);
        genPascalsTriangle(numRows, triangle, layer+1);
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        genPascalsTriangle(numRows, triangle, 0);
        return triangle;
    }
};