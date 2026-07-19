class Solution {
public:
    int furthestBuilding(vector<int>& heights, int b, int l) {
        priority_queue<int> pq;
        int n = heights.size();
        for(int i = 1; i < n; ++i){
            int h = heights[i] - heights[i-1];
            if(h <= 0) continue;

            pq.push(h);
            if(b < h){
                if(l == 0) return i-1;
                // use ladder
                b += pq.top(); pq.pop();
                --l;
            }
            
            b -= h;
        }
        return n-1;
    }
};