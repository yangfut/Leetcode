class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        // Champion means no one beats him/her
        for(const auto edge : edges){
            ++indegree[edge[1]];
        }

        int champ = -1;
        for(int i = 0; i < n; ++i){
            if(indegree[i] == 0 && champ == -1) champ = i;
            else if(indegree[i] == 0 && champ != -1) return -1;
        }
        return champ;
    }
};