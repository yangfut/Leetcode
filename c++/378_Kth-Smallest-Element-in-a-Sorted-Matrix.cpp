class Solution {
public:
    //#1 Binary Search
    //TC: N, SC: 1
    int search_less_equal(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int i = n-1, j = 0, res = 0;
        while(i>=0 && j < n){
            if(matrix[i][j] > target) --i;
            else{
                res += i+1;
                ++j;
            }
        }
        return res;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int leftVal = matrix[0][0];
        int rightVal = matrix.back().back();
        int midVal, count;
        while(leftVal < rightVal) {
            midVal = leftVal + (rightVal-leftVal) / 2;
            count = search_less_equal(matrix, midVal);
            if(count < k) leftVal = midVal+1;
            else rightVal = midVal;
        }
        return leftVal;
    }
    //#2 Priority Queue(max heap)
    //TC: N*N*logN, SC: K
    /*
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> maxHeap;

        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(maxHeap.size() < k) maxHeap.push(matrix[i][j]);
                else{
                    if(matrix[i][j] < maxHeap.top()){
                        maxHeap.pop();
                        maxHeap.push(matrix[i][j]);
                    }
                }
            }
        }
        return maxHeap.top();
    }
    */
    
    //#3 Priority Queue(Min Heap)
    //TC: N*N*logN, SC: N*N
    /*
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                minHeap.push(matrix[i][j]);
            }
        }

        while(k>1) {
            minHeap.pop();
            k--;
        }
        return minHeap.top();
    }
    */

    //#4 Sort(Brute-Force)
    //TC: N*N, SC:N
    /*
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> vec;
        int n = matrix.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                vec.push_back(matrix[i][j]);
            }
        }

        sort(vec.begin(), vec.end());
        return vec[k-1];
    }
    */
};