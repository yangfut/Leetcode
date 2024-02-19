class Solution {
public:
    bool binary_search(vector<vector<int>>& matrix, int target, int x, int low, int high){
        if(low>high) return false;

        int mid=low+(high-low)/2;

        if(matrix[x][mid]==target) return true;
        else if(matrix[x][mid]<target) low=mid+1;
        else high=mid-1;
        return binary_search(matrix, target, x, low, high);
    }

    bool bf_solution(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int max_n=n-1;
        int min_n=0;
        int max_m=m-1;
        int min_m=0;
        while(matrix[max_n][0]>target && max_n>0) max_n--;
        while(matrix[0][max_m]>target && max_m>0) max_m--;

        while(matrix[min_n][m-1]<target && min_n<max_n) min_n++;
        while(matrix[n-1][min_m]<target && min_m<max_m) min_m++;

        //search every rows with binary search
        for(int x=min_n;x<=max_n;x++) if(binary_search(matrix, target, x, min_m, max_m)) return true;
        return false;
    }

    bool top_right_solution(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int c=m-1;
        int r=0;

        while(c>=0 && r<n){
            if(matrix[r][c]==target) return true;
            matrix[r][c]>target? c--:r++;
        }
        return false;
    }

    bool binary_search_solution(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = row ? matrix[0].size() : 0;
        int st = 0, ed = row-1, mid, endRow, startRow;

        //determine start row by implementing lower bound binary serach
        while(st<ed){
            mid=st+(ed-st)/2;
            if(matrix[mid][col-1]<target) st=mid+1;
            else ed=mid;
        }
        startRow=st;

        //determine end row by implementing upper bound binary search
        st=0, ed=row-1;
        while(st<ed){
            mid=st+(ed-st)/2;
            if(matrix[mid][0]<=target) st=mid+1;
            else ed=mid;
        }
        endRow=st;

        //search each row by lower bound binary serach
        for(int i=startRow;i<=endRow;i++){
            st=0, ed=col-1;
            while(st<ed){
                mid=st+(ed-st)/2;
                if(matrix[i][mid]<target) st=mid+1;
                else ed=mid;
            }
            if(matrix[i][st]==target) return true;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //#1 brute-force solution with binary search
        //return bf_solution(matrix, target);

        //#2 Top-right solution
        //return top_right_solution(matrix, target);

        //#3 Binary Search
        return binary_search_solution(matrix, target);
    }
};