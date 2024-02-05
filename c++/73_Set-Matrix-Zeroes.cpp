class Solution {
public:
    void setRowColTwoZeros(vector<vector<int>>& matrix, int row, int column, int direct){
        if(row==matrix.size()||row<0||column==matrix[0].size()||column<0) return;

        matrix[row][column]=0;

        //Up
        if(0==direct) row--;
        //Down
        else if(1==direct) row++;
        //Left
        else if(2==direct) column--;
        //Right
        else if(3==direct) column++;

        setRowColTwoZeros(matrix, row, column, direct);
    }
    void bfs_solution(vector<vector<int>>& matrix) {
        stack<int>colZeroStack;
        stack<int>rowZeroStack;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(0==matrix[i][j]){
                    colZeroStack.push(j);
                    rowZeroStack.push(i);
                }
            }
        }

        int row;
        int column;
        while(!colZeroStack.empty()){
            row=rowZeroStack.top();
            column=colZeroStack.top();

            setRowColTwoZeros(matrix, row, column, 0); //Go up
            setRowColTwoZeros(matrix, row, column, 1); //Go down
            setRowColTwoZeros(matrix, row, column, 2); //Go left
            setRowColTwoZeros(matrix, row, column, 3); //Go right
            
            rowZeroStack.pop();
            colZeroStack.pop();
        }
    }

    void projection_solution(vector<vector<int>>& matrix) {
        bool isRowZero=false;
        bool isColZero=false;

        //Check first row
        for(int j=0;j<matrix[0].size();j++){
            if(0==matrix[0][j]) isRowZero=true;
        }

        //Check first column
        for(int i=0;i<matrix.size();i++){
            if(0==matrix[i][0]) isColZero=true;
        }

        //Projection
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(0==matrix[i][j]){
                    matrix[i][0]=0; //Mark the row
                    matrix[0][j]=0; //Mark the column
                }
            }
        }
        //Process the entire row
        for(int i=1;i<matrix.size();i++){
            if(0==matrix[i][0]){
                for(int j=1;j<matrix[0].size();j++) matrix[i][j]=0;
            }
        }
        //Process the entire column
        for(int j=1;j<matrix[0].size();j++){
            if(0==matrix[0][j]){
                for(int i=1;i<matrix.size();i++) matrix[i][j]=0;
            }
        }
        //Proces the first row
        if(isRowZero){
            for(int j=0;j<matrix[0].size();j++) matrix[0][j]=0;
        }
        //Proces the first column
        if(isColZero){
            for(int i=0;i<matrix.size();i++) matrix[i][0]=0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        //#1 BFS
        //bfs_solution(matrix);

        //#2 Projection
        projection_solution(matrix);

    }
};