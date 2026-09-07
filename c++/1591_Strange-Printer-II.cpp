class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        unordered_map<int,vector<int>> colorMap;
        int n = targetGrid.size(), m = targetGrid[0].size();
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < m; ++c){
                int clr = targetGrid[r][c];
                if(!colorMap.count(clr)){
                    colorMap[clr] = {r,r,c,c};
                }else{
                    vector<int>& rec = colorMap[clr];
                    rec[0] = min(rec[0], r);
                    rec[1] = max(rec[1], r);
                    rec[2] = min(rec[2], c);
                    rec[3] = max(rec[3], c);
                }
            }
        }

        unordered_map<int,unordered_set<int>> edge;
        unordered_map<int, int>indegree;
        for(auto&clr : colorMap) indegree[clr.first] = 0;
        for(auto& clr : colorMap){
            int currColor = clr.first;
            vector<int>& rec = clr.second;
            for(int r = rec[0]; r <= rec[1]; ++r){
                for(int c = rec[2]; c <= rec[3]; ++c){
                    int tarColor = targetGrid[r][c];
                    if(tarColor != currColor && !edge[currColor].count(tarColor)){
                        ++indegree[tarColor];
                        edge[currColor].insert(tarColor);
                    }
                }
            }
        }

        queue<int>q;
        for(auto& [clr, deg] : indegree) {
            if(deg == 0) q.push(clr);
        }
        
        while(!q.empty()){
            int clr = q.front();
            q.pop();
            for(int nextclr : edge[clr]){
                --indegree[nextclr];
                if(indegree[nextclr] == 0) q.push(nextclr);
            }
        }

        for(auto& [clr, deg] : indegree) if(deg > 0) return false;
        return true;
    }
};