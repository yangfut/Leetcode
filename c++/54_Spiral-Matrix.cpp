class Solution {
public:
    void move_right(vector<vector<int>>& matrix, int x, int y, vector<int>& spiralArr){
        if(y==matrix[0].size()||matrix[x][y]==101) return;
        spiralArr.push_back(matrix[x][y]);
        matrix[x][y]=101; //Mark visited
        move_right(matrix, x, y+1, spiralArr);
        move_down(matrix, x+1, y, spiralArr);
    }
    void move_down(vector<vector<int>>& matrix, int x, int y, vector<int>& spiralArr){
        if(x==matrix.size()||matrix[x][y]==101) return;
        spiralArr.push_back(matrix[x][y]);
        matrix[x][y]=101; //Mark visited
        move_down(matrix, x+1, y, spiralArr);
        move_left(matrix, x, y-1, spiralArr);
    }
    void move_left(vector<vector<int>>& matrix, int x, int y, vector<int>& spiralArr){
        if(y<0||matrix[x][y]==101) return;
        spiralArr.push_back(matrix[x][y]);
        matrix[x][y]=101; //Mark visited
        move_left(matrix, x, y-1, spiralArr);
        move_up(matrix, x-1, y, spiralArr);
    }
    void move_up(vector<vector<int>>& matrix, int x, int y, vector<int>& spiralArr){
        if(x<0||matrix[x][y]==101) return;
        spiralArr.push_back(matrix[x][y]);
        matrix[x][y]=101; //Mark visited
        move_up(matrix, x-1, y, spiralArr);
        move_right(matrix, x, y+1, spiralArr);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiralArr;
        move_right(matrix, 0, 0, spiralArr);
        return spiralArr;
    }
};