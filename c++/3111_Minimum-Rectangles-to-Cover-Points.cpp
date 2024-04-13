class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        set<int> xSet;
        for(auto& p:points) xSet.insert(p[0]);
        vector<int> xVec(xSet.begin(), xSet.end());
        sort(xVec.begin(), xVec.end());
        
        int rectCount=0, rectBound=-1;
        for(int x:xVec){
            if(x>rectBound){
                rectBound=x+w;
                ++rectCount;
            }
        }
        
        return rectCount;
        
    }
};