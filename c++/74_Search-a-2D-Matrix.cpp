class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m*n;

        while(low<high){
            int mid = low + (high-low)/2;
            int row = mid/n;
            int col = mid%n;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) high = mid;
            else low = mid + 1;
        }
        return false;
    }
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     //binary serach for the first element in all rows
    //     int low=0, high=matrix.size();
    //     while(low<high){
    //         int mid=low+(high-low)/2;
    //         if(matrix[mid][0]==target) return true;
    //         else if(matrix[mid][0]>target) high=mid;
    //         else low=mid+1;
    //     }
        
    //     int row = (low==0)? low:low-1;
    //     low=0, high=matrix[0].size();
    //     //binary search for that specific row
    //     while(low<high){
    //         int mid=low+(high-low)/2;
    //         if(matrix[row][mid]==target) return true;
    //         else if(matrix[row][mid]>target) high=mid;
    //         else low = mid+1;
    //     }
        
    //     return false;
    // }
};