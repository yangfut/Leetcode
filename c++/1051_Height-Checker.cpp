class Solution {
public:
    int heightChecker(vector<int>& heights) {
        priority_queue<int, vector<int>, greater<int>> pq; //min heap
        int n = heights.size(), mismatchCount = 0;
        for(int& val : heights) pq.push(val);
        for(int& val : heights){
            if(val != pq.top()) ++mismatchCount;
            pq.pop();
        }
        return mismatchCount;
    }
};