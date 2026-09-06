class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> indegree(n,0);
        for(int i = 0; i < n; ++i){
            indegree[edges[i]] += i;
        }
        long long gMax = 0, node = -1;
        for(int i = 0; i < n; ++i){
            long long val = indegree[i];
            if(val > gMax) {
                node = i;
                gMax = val;
            }
        }
        return node;
    }
};