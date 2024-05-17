class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> mapPoint;
        int minArea = INT_MAX, n = points.size();
        
        for(auto& p : points) mapPoint[p[0]].insert(p[1]);

        // find diagonal points p1 = (x1, y1) & p2 = (x2, y2)
        for(int idx1 = 0; idx1 < n; ++idx1){
            for(int idx2 = idx1+1; idx2 < n; ++idx2){
                int x1 = points[idx1][0];
                int y1 = points[idx1][1];
                int x2 = points[idx2][0];
                int y2 = points[idx2][1];

                // exclude if p1 and p2 are in line
                if(x1 == x2 || y1 == y2) continue;

                if(mapPoint[x1].count(y2) && mapPoint[x2].count(y1)){
                    minArea = min(minArea, abs(x2-x1)*abs(y2-y1));
                }
            }
        }
        return (minArea == INT_MAX) ? 0 : minArea;
    }
};